#include "PreCompile.h"
#include "SWRamyeon.h"

namespace ksw
{
	RamyeonStore::RamyeonStore(size_t _StoveCount, size_t _RamyeonCount)
		: StoveCount(_StoveCount), RamyeonCount(_RamyeonCount)
	{
	}

	RamyeonStore::~RamyeonStore()
	{
	}

	void RamyeonStore::Cooking()
	{
		std::function MakeRamyeon = [&](size_t _JobCount, std::mutex& _Mutex)
			{ 
				std::thread::id ID = std::this_thread::get_id();
				for (size_t i = 0; i < _JobCount; i++)
				{
					std::lock_guard<std::mutex> lock(_Mutex);
					++SellRamyeonCount;

					//std::cout << SellRamyeonCount << std::endl;
					//printf_s("Thread %x : %lu \n", ID, SellRamyeonCount);
				}
			};

		std::mutex Mutex;
		size_t JobCount = RamyeonCount / StoveCount;
		
		Stove.reserve(StoveCount);
		for (size_t i = 0; i < StoveCount; i++)
		{
			std::thread* NewStove = new std::thread(MakeRamyeon, JobCount, std::ref(Mutex));
			Stove.push_back(NewStove);
		}

		for (size_t i = 0; i < Stove.size(); i++)
		{
			Stove[i]->join();
			delete Stove[i];
		}

		Stove.clear();
	}

	void RamyeonStore::BeforeInfo()
	{
		std::cout << "\n** SW_Ramyeon **" << std::endl;
		std::cout << "목표 판매량 : " << RamyeonCount << std::endl;
		std::cout << std::endl;
	}

	void RamyeonStore::AfterInfo()
	{
		std::cout << "영업 후 판매 수 : " << SellRamyeonCount << std::endl;
		std::cout << "오차 : " << RamyeonCount - SellRamyeonCount << std::endl;
		std::cout << std::endl;
	}
}
