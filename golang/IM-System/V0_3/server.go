package main

import (
	"fmt"
	"io"
	"net"
	"sync"
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
	user := NewUser(conn)

	//用户上线，将用户加入到onlineMap中
	this.mapLock.Lock()
	this.onlineMap[user.Name] = user
	this.mapLock.Unlock()

	//广播当前用户上线
	this.BroadCast(user, "已上线      ")

	//接手客户端发送的消息
	go func() {
		buf := make([]byte, 4096)
		for {
			n, err := conn.Read(buf)
			if n == 0 {
				this.BroadCast(user, "下线了")
				return
			}
			if err != nil && err != io.EOF {
				fmt.Println("Conn Read err:", err)
				return
			}
			//将用户消息提取（去除'\n'）
			msg := string(buf[:n-1])

			//将用户的消息广播
			this.BroadCast(user, msg)

		}
	}()

	//当前handler阻塞
	select {}
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
