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
	WSError(std::string &&str) : 
		std::runtime_error(
			[this, &str] {
				error = WSAGetLastError();
				return(str + ", код " +
					   std::to_string(error));
			}()) {}
	int getCode() const {
		return error;
	}
};