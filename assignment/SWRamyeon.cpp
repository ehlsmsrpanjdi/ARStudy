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
		std::function MakeRamyeon = [this](size_t _JobCount)
			{ 
				std::thread::id ID = std::this_thread::get_id();
				for (size_t i = 0; i < _JobCount; i++)
				{
					++SellRamyeonCount;
					--RamyeonCount;
					//std::cout << SellRamyeonCount << std::endl;
					//printf_s("Thread %x : %lu \n", ID, SellRamyeonCount);
				}
			};

		size_t JobCount = RamyeonCount / StoveCount;
		Stove.reserve(StoveCount);
		for (size_t i = 0; i < StoveCount; i++)
		{
			std::thread* NewStove = new std::thread(MakeRamyeon, JobCount);
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
		std::cout << "영업 전 라면 수 : " << RamyeonCount << std::endl;
		std::cout << "영업 전 판매 수 : " << SellRamyeonCount << std::endl;
		std::cout << std::endl;
	}

	void RamyeonStore::AfterInfo()
	{
		std::cout << "영업 후 라면 수 : " << RamyeonCount << std::endl;
		std::cout << "영업 후 판매 수 : " << SellRamyeonCount << std::endl;
		std::cout << std::endl;
	}
}
