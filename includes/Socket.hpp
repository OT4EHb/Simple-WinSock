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
	void setInfo(const std::string &hoststr, const std::string &port, int type, int af);
	u_short getInfo(std::string &) const;
public:
	Socket(const std::string &hoststr, const std::string &port, int type, int af);
	~Socket() noexcept;
	Socket(Socket &) = delete;
	Socket(Socket &&) noexcept;
	Socket &operator=(const Socket &) = delete;
	void bind() const;
	void setEvent(WSEvent &, long) const;
	DWORD checkEvent(WSEvent &) const;
};
