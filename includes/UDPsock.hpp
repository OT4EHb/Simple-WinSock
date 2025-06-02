#pragma once
#include <Socket.hpp>

class UDPsock : public Socket {
protected:
	UDPsock() :Socket() {}
public:
	UDPsock(const std::string &hoststr, const std::string &port = "80",
			int af = AF_INET) :
		Socket(hoststr, port, SOCK_DGRAM, af) {}
	int send(const char *pack, size_pack sizePack, int flags = 0);
	int recv(char *pack, size_pack sizePack, int flags = 0);
};