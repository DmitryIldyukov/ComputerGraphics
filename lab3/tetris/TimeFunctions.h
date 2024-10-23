#pragma once
#include <ctime>
#include <cstdlib>

inline void WaitTime(int ms) {

	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
	clock_t end_time = clock() + ms * CLOCKS_PER_MSEC;
	while (clock() < end_time) {}
}

inline int GenerateRandomIndex() {
	srand(static_cast<unsigned int>(time(0)));
	return rand() % 7;
}