#include "TCPsock.hpp"

int main() {
	try {
		WSStart::init();
		TCPsock sk{"localhost"};
		sk.bind();
		sk.listen();
		TCPsock s = sk.accept();
		char buff[100]{"Вас ис дас\n"};
		s.send(buff, 100);
	}
	catch (WSError &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Нажмите Enter";
	std::getchar();
	return 0;
}