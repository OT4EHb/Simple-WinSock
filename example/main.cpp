#include "Socket.hpp"

int main() {
	try {
		WSStart::init();
		Socket sk{"localhost"};
		sk.bind();
	}
	catch(WSError&e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Нажмите Enter";
	std::getchar();
	return 0;
}
