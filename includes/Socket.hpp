#pragma once
#include <WSStart.hpp>
#include <WS2tcpip.h>

//Базовый класс сокетов, от которого следует наследоваться
class Socket {
protected:
	SOCKET sock;
	addrinfo sinfo;
	sockaddr saddr;
	Socket();
	void setInfo(std::string hoststr, std::string port, int type, int af);
	u_short getInfo(std::string &) const;
public:
	Socket(std::string hoststr, std::string port, int type, int af);
	~Socket() noexcept;
	Socket(Socket &) = delete;
	Socket(Socket &&) noexcept;
	Socket &operator=(const Socket &) = delete;
	void bind() const;
	void setEvent(WSEvent &, long) const;
};
