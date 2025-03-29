#pragma once

#include "WSconfig.hpp"
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
#include <stdexcept>
#include <string>
#ifdef WSDEBUG
#include <iostream>
#endif

//ПАТТЕРН ОДИНОЧКА ПО САМУСЕВУ
class WSStart {
private:
	WSADATA ws;
	WSStart(int major = 2, int minor = 2);
	~WSStart();
public:
	static WSStart &init();
};