#include "WSStart.hpp"
#include <io.h>
#include <fcntl.h>

using std::wcout;

int wmain() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	WSStart::init();
	return 0;
}
