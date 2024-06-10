#pragma once
#include <atomic>
#include <vector>
#include <thread>

class YDRamyeon
{
public:
	YDRamyeon();
	~YDRamyeon();

	void Ramyeon();
protected:

private:
	std::vector<std::thread*> Threads;
};

