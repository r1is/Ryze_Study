package main

import (
	"fmt"
	"io"
	"net"
	"sync"
	"time"
)

type Server struct {
	Ip   string
	Port int
	//在线用户列表
	onlineMap map[string]*User
	mapLock   sync.RWMutex
	//消息广播的channel
	Message chan string
}

//创建一个server的接口
func NewServer(ip string, port int) *Server {
	server := &Server{
		Ip:        ip,
		Port:      port,
		onlineMap: make(map[string]*User),
		Message:   make(chan string),
	}
	return server
}

//监听Messaged广播消息channel的方法goroutine
func (this *Server) ListenMessage() {
	for {
		msg := <-this.Message

		//将msg发送给全部在线的User
		this.mapLock.Lock()
		for _, cli := range this.onlineMap {
			cli.C <- msg

		}
		this.mapLock.Unlock()
	}
}

//广播消息的方法
func (this *Server) BroadCast(user *User, msg string) {
	sendMsg := "[" + user.Addr + "]" + user.Name + ":" + msg
	this.Message <- sendMsg

}
func (this *Server) Hanlder(conn net.Conn) {
	//当前连接的业务

	//fmt.Println("连接建立成功")
	user := NewUser(conn, this)

	//用户上线
	user.Online()
	//监听客户端是否活跃的channel
	isLive := make(chan bool)
	//接手客户端发送的消息
	go func() {
		buf := make([]byte, 4096)
		for {
			n, err := conn.Read(buf)
			if n == 0 {
				user.Offline()
				return
			}
			if err != nil && err != io.EOF {
				fmt.Println("Conn Read err:", err)
				return
			}
			//将用户消息提取（去除'\n'）
			msg := string(buf[:n-1])

			//用户针对msg进行消息处理
			user.DoMessage(msg)
			//用户的任意消息，代表当前用户是活跃的
			isLive <- true
		}
	}()

	//当前handler阻塞
	for {
		select {
		case <-isLive:
			//当前用户是活跃的，应该重置定时器
			//不做任何操作，为了激活select,更新下面的定时器
		case <-time.After(time.Second * 60):
			//已经超时
			//将当前的User强制关闭

			user.SendMsg("长时间未活动，超时下线\n")

			//销毁用户资源
			close(user.C)

			//关闭连接
			conn.Close()

			//退出当前Handler
			return
		}
	}
}

//启动服务器的接口
func (this *Server) Start() {
	//socket listen
	listener, err := net.Listen("tcp", fmt.Sprintf("%s:%d", this.Ip, this.Port))
	if err != nil {
		fmt.Println("net.Listen err :", err)
	}
	//close listen socket
	defer listener.Close()

	//启动监听Message的goroutine
	go this.ListenMessage()

	for {
		//accept
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("listen accept err:", err)
			continue
		}
		//do handler
		go this.Hanlder(conn)
	}

}
