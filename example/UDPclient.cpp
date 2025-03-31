#include "UDPsock.hpp"

int main() {
	try {
		WSStart::init();
		UDPsock sk{"127.0.0.1"};
		char buff[100]{"Полезная информация\n"};
		sk.send(buff, 100);
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