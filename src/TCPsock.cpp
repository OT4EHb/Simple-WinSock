#include <TCPsock.hpp>

void TCPsock::listen(int backlog) {
	if (::listen(sock, backlog)) {
		throw WSError("Ошибка при прослушивании");
	}
	std::cout << "Слушаем...\n";
}

TCPsock TCPsock::accept() {
	TCPsock sk;
	sk.sock = ::accept(sock, sk.sinfo.ai_addr,
					   reinterpret_cast<int *>(&sk.sinfo.ai_addrlen));
	sk.sinfo.ai_family = sk.sinfo.ai_addr->sa_family;
	if (sk.sock == INVALID_SOCKET) {
		throw WSError("Ошибка при принятии клиента");
	}
	std::cout << "Подключен клиент:\n";
	sk.getInfo();
	return sk;
}

void TCPsock::connect() {
	if (::connect(sock, sinfo.ai_addr, sinfo.ai_addrlen)) {
		throw WSError("Ошибка при подключении");
	}
#ifdef WSDEBUG
	std::cout << "Успешно подключено\n";
#endif
}

int TCPsock::send(const char *pack, size_pack sizePack, int flags) {
	int size = ::send(this->sock, pack, sizePack, flags);
	if (size == SOCKET_ERROR) {
		throw WSError("Ошибка при отправке");
	}
	return size;
}

int TCPsock::recv(char *pack, size_pack sizePack, int flags) {
	int size = ::recv(this->sock, pack, sizePack, flags);
	if (size == SOCKET_ERROR) {
		throw WSError("Ошибка при получении");
	}
	return size;
}