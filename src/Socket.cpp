#include <Socket.hpp>

Socket::Socket() {
	ZeroMemory(this, sizeof(Socket));
	sock = INVALID_SOCKET;
	sinfo.ai_addr = &saddr;
	sinfo.ai_addrlen = sizeof(saddr);
}

void Socket::setInfo(std::string hoststr, std::string port, int type, int af) {
	addrinfo hints, *result = nullptr;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = af;
	hints.ai_socktype = type;
	if (getaddrinfo(hoststr.c_str(), port.c_str(), &hints, &result)) {
		throw WSError("DNS сервер сказал, что вы многоуважаемый человек");
	}
	memcpy(&sinfo, result, sizeof(*result));
	memcpy(&saddr, sinfo.ai_addr, sizeof(sinfo.ai_addr));
	sinfo.ai_addr = &saddr;
	freeaddrinfo(result);
#ifdef WSDEBUG
	getInfo();
#endif
}

void Socket::getInfo() {
	char IP[INET6_ADDRSTRLEN];
	if (inet_ntop(sinfo.ai_family, reinterpret_cast<char *>(sinfo.ai_addr) + 4,
				  IP, INET6_ADDRSTRLEN) != nullptr) {
		std::cout << "IP " << IP << std::endl
			<< "Port " << ntohs(*reinterpret_cast<u_short*>(reinterpret_cast<char *>(sinfo.ai_addr) + 2)) << std::endl;
	}
}

Socket::Socket(std::string hoststr, std::string port, int type, int af) :
	sock(socket(af, type, 0)) {
	if (sock == INVALID_SOCKET) {
		throw WSError("Ошибка при создании сокета");
	}
	setInfo(std::move(hoststr), std::move(port), type, af);
#ifdef WSDEBUG
	std::cout << "Открытие сокета\n";
#endif
}
Socket::~Socket() {
	closesocket(sock);
#ifdef WSDEBUG
	std::cout << "Закрытие сокета\n";
#endif
}

Socket::Socket(Socket &sk)  {
	memcpy(this, &sk, sizeof(Socket));
	sinfo.ai_addr = &saddr;
	sk.sock = INVALID_SOCKET;
}

void Socket::bind() const {
	if (::bind(sock, sinfo.ai_addr, sinfo.ai_addrlen)) {
		throw WSError("Ошибка при связывании сокета");
	}
}