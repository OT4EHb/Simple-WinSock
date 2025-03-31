#include "UDPsock.hpp"

int main() {
	try {
		WSStart::init();
		UDPsock sk{"localhost"};
		sk.bind();
		char buff[100]{""};
		sk.recv(buff, 100);
		buff[0] = 'S';
		buff[1] = 'R';
		sk.send(buff, 100);
	}
	catch (WSError &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Нажмите Enter";
	std::getchar();
	return 0;
}