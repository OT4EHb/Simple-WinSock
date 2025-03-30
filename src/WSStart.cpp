#include "WSStart.hpp"

WSStart::WSStart(int major, int minor) {
	SetConsoleOutputCP(CP_UTF8);
	if (WSAStartup(MAKEWORD(major, minor), &ws)) {
		throw WSError("Ошибка при инизиализации библиотеки");
	}
#ifdef WSDEBUG
	std::cout << "Запущена библиотека версии " <<
		static_cast<int>HIBYTE(ws.wVersion) << '.' <<
		static_cast<int>LOBYTE(ws.wVersion) << std::endl;
#endif
}

WSStart::~WSStart() {
	WSACleanup();
#ifdef WSDEBUG
	std::cout << "Библиотека отключена\n";
#endif
}

WSStart &WSStart::init(int major, int minor) {
	static WSStart st{major, minor};
	return st;
}