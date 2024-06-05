#pragma once
#include <functional>

class SMCal {
public:

	std::function<int(int, int)> Fun;
	int Result;
};

class SMUser {
public:
	SMCal Cal;

	void Select(int _Left, char _Which, int _Right);
};