#pragma once
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include <string>
#include <stdexcept>

class WSError : public std::runtime_error {
private:
	int error;
	int : 32;
public:
	WSError(const std::string str) : error(WSAGetLastError()),
		std::runtime_error(std::move(str + ", код " +
									 std::to_string(error))) {}
	int getCode() const {
		return error;
	}
};