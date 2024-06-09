#include "PreCompile.h"
#include "JWRamyeon.h"

JWRamyeon::JWRamyeon()
{
}

JWRamyeon::~JWRamyeon()
{
}

void JWRamyeon::Open()
{
	Count = 0;
	RamyeonMachine.resize(MachineCount);
	MachinePerOrder = OrderCount / MachineCount;

	std::function<void(int, std::mutex&) > Cooking = [&](int Index, std::mutex& _M)
		{
			for (int i = 0; i < MachinePerOrder; i++)
			{
				_M.lock();
				std::cout << Index << "기계 라면 : " << ++Count << "개 끓임" << std::endl;
				_M.unlock();
			}
		};

	std::mutex m;
	for (int i = 0; i < MachineCount; i++)
	{
		std::thread* NewThread = new std::thread(Cooking, i + 1, std::ref(m));
		RamyeonMachine[i] = NewThread;
	}

	RamyeonOrder();
}

void JWRamyeon::RamyeonOrder()
{
	for (int i = 0; i < RamyeonMachine.size(); i++)
	{
		RamyeonMachine[i]->join();
		delete RamyeonMachine[i];
	}

	RamyeonMachine.clear();

	Result();
}

void JWRamyeon::Result()
{
	std::cout << Count << "개 완료";
}
