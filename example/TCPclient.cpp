#include "TCPsock.hpp"

int main() {
	try {
		WSStart::init();
		TCPsock sk{"127.0.0.1"};
		char buff[100]{0};
		sk.connect();
		sk.recv(buff, 100);
		std::cout << buff;
	}
	catch (WSError &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Нажмите Enter";
	std::getchar();
	return 0;
}