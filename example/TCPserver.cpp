#include <TCPsock.hpp>

int main() {
	try {
		WSStart::init();
		TCPsock sk{""};
		sk.bind();
		sk.listen();
		TCPsock s = sk.accept();
		char buff[100]{"Вас ис дас\n"};
		s.send(buff, 100);
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