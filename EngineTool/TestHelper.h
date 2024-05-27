#pragma once
#include "EngineTime.h"

#define CONCAT(a, b) CONCAT_INNER(a, b)

#define CONCAT_INNER(a, b) a ## b

#define TimeTest(Name) TimeTestHelper CONCAT(f8c7afec, __COUNTER__)(std::string(Name));

class TimeTestHelper
{
public:
	TimeTestHelper() {}

	TimeTestHelper(std::string_view _TestName)
	{
		TestName = _TestName;
		Timer.Reset();
	}

	~TimeTestHelper()
	{
		double Time = Timer.TimeCheck();
		std::cout << "[" << TestName << "] " << Time << "ÃÊ" << std::endl;
	}
private:
	EngineTime Timer;
	std::string TestName;
};


