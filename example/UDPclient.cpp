#include <UDPsock.hpp>

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
	catch (...) {
		throw;
	}
	std::cout << "Нажмите Enter";
	_getwch();
	return 0;
}