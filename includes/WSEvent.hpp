#pragma once
#include <WSError.hpp>

class WSEvent {
private:
	WSAEVENT event;
public:
	WSEvent() :event(WSACreateEvent()) {}
	~WSEvent() {
		WSACloseEvent(event);
	}
	WSEvent(const WSEvent &) = delete;
	WSEvent &operator=(const WSEvent &) = delete;
	const WSAEVENT get() const {
		return event;
	}
	DWORD wait(DWORD timeout = 500ul) const {
		DWORD result = WSAWaitForMultipleEvents(1, &event, TRUE, timeout, FALSE);
		if (result == WSA_WAIT_FAILED) throw WSError("Ошибка ожидания события");
		return result;
	}
	void reset() const {
		if (WSAResetEvent(event)) return;
		throw WSError("Ошибка при сбросе события");
	}
};