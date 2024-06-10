#include "PreCompile.h"
#include "YDRamyeon.h"
#include <iostream>
#include <mutex>

YDRamyeon::YDRamyeon()
{
}

YDRamyeon::~YDRamyeon()
{
	for (int i = 0; i < 4; i++)
	{
		delete Threads[i];
	}
}

void Cook(int& count, std::mutex& m)
{
	m.lock();
	while (count < 100000)
	{
		++count;
	}
	m.unlock();
}

void YDRamyeon::Ramyeon()
{
	int count = 0;
	std::mutex m;

	Threads.resize(4);

	for (int i = 0; i < 4; i++)
	{
		Threads[i] = new std::thread(Cook, std::ref(count), std::ref(m));
	}

	bool Done = false;
	while (!Done)
	{
		for (int i = 0; i < 4; i++)
		{
			Done = true;
			if (!Threads[i]->joinable())
			{
				Done = false;
			}
		}
	}


	for (int i = 0; i < 4; i++)
	{
		Threads[i]->join();
	}

	std::cout << "YD Ramyeon : " << count << std::endl;

}