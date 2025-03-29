#include "WSStart.hpp"

WSStart::WSStart(int major, int minor) {
	if (WSAStartup(MAKEWORD(major, minor), &ws)) {
		throw std::runtime_error("Error WinSock init, code "
								 + std::to_string(WSAGetLastError()));
	}
#ifdef WSDEBUG
	std::wcout << L"Запущена библиотека версии " <<
		HIBYTE(ws.wVersion) << L'.' <<
		LOBYTE(ws.wVersion) << std::endl;
#endif
}

WSStart::~WSStart() {
	WSACleanup();
#ifdef WSDEBUG
	std::wcout << L"Библиотека отключена\n";
#endif
}

WSStart & WSStart::init() {
	static WSStart st{};
	return st;
}