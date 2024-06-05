#pragma once
#include <functional>

class SMCal {
public:

	std::function<int(int, int)> Fun;
	std::function<void()> ValueResult;
	int Result;
};

class SMUser {
public:

	void Select(int _Left, char _Which, int _Right);
};