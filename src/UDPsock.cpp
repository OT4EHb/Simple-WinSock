#include "UDPsock.hpp"

int UDPsock::send(const char *pack, size_pack sizePack, int flags) {
	int size = ::sendto(this->sock, pack, sizePack, flags,
						sinfo.ai_addr, sinfo.ai_addrlen);
	if (size == SOCKET_ERROR) {
		throw WSError("Ошибка при отправке");
	}
	return size;
}

int UDPsock::recv(char *pack, size_pack sizePack, int flags) {
	int size = ::recvfrom(this->sock, pack, sizePack, flags,
						  sinfo.ai_addr, reinterpret_cast<int *>(&sinfo.ai_addrlen));
	if (size == SOCKET_ERROR) {
		throw WSError("Ошибка при получении");
	}
	return size;
}