package main

func main() {
	server := NewServer("172.28.176.24", 8888)
	server.Start()
}
