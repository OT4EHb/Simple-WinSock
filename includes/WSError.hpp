#pragma once
#include <WinSock2.h>
#include <string>
#include <stdexcept>

class WSError : public std::runtime_error {
public:
	WSError(const std::string str) :
		std::runtime_error(str + ", код " +
						   std::to_string(WSAGetLastError())) {}
};