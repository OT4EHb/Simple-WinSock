#pragma once

#include <WSconfig.hpp>
#include <WSEvent.hpp>

//ПАТТЕРН ОДИНОЧКА ПО САМУСЕВУ
class WSStart {
private:
	WSADATA ws;
	WSStart(int major, int minor);
	~WSStart();
public:
	static WSStart &init(int major = 2, int minor = 2);
};