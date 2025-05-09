#include <TCPsock.hpp>
#include <iostream>

int main() {
	try {
		WSStart::init();
		TCPsock sk{""};
		sk.bind();
		sk.listen();
		WSEvent e{};
		sk.setEvent(e, FD_ACCEPT);
		size_t second{0};
		while (true) {
			if (e.wait() == WSA_WAIT_TIMEOUT) {
				std::cout << "Ждём клиента уже " << (second += 3) << " секунд\n";
			}
			else break;
		}
		if (sk.checkEvent(e) & FD_ACCEPT) {
			std::cout << "Клиент пришёл\n";
		}
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