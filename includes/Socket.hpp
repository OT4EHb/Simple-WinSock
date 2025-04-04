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
	void getInfo();
public:
	Socket(std::string hoststr, std::string port, int type, int af);
	~Socket() noexcept;
	Socket(Socket &sk); //На случай копирования/не сработает NRVO
	Socket &operator=(const Socket &) = delete;
	void bind() const;
};
