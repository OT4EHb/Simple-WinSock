#include <TCPsock.hpp>

int main() {
	try {
		WSStart::init();
		TCPsock sk{""};
		char buff[100]{0};
		sk.connect();
		sk.recv(buff, 100);
		std::cout << buff;
	}
	catch (WSError &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		throw;
	}
	std::cout << "Нажмите Enter\n";
	_getwch();
	return 0;
}