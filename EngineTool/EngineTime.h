#pragma once
#include <Windows.h>

// Ό³Έν :
class EngineTime
{
public:
	// constructor destructor
	EngineTime();
	~EngineTime();

	// delete Function
	EngineTime(const EngineTime& _Other) = delete;
	EngineTime(EngineTime&& _Other) noexcept = delete;
	EngineTime& operator=(const EngineTime& _Other) = delete;
	EngineTime& operator=(EngineTime&& _Other) noexcept = delete;

	void Reset();
	double TimeCheck();
protected:

private:
	LARGE_INTEGER Count;
	LARGE_INTEGER Frequency;
};

