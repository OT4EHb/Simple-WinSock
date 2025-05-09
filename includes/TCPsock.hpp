#pragma once
#include <Socket.hpp>

class TCPsock : public Socket {
protected:
	TCPsock() :Socket() {}
public:
	TCPsock(std::string hoststr, std::string port = "80", int af = AF_INET) :
		Socket(hoststr, port, SOCK_STREAM, af) {}
	void listen(int backlog = SOMAXCONN);
	TCPsock accept();
	void connect();
	int send(const char *pack, size_pack sizePack, int flags = 0);
	int recv(char *pack, size_pack sizePack, int flags = 0);
};