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

	void RamyeonStore::Cooking(ECookType _CookType)
	{
		BeforeInfo();

		std::function MakeRamyeon = [&](size_t _JobCount, std::mutex& _Mutex, ECookType _CookType)
			{ 
				std::thread::id ID = std::this_thread::get_id();
				for (size_t i = 0; i < _JobCount; i++)
				{
					switch (_CookType)
					{
					case ksw::ECookType::Mutex:
					{
						std::lock_guard<std::mutex> lock(_Mutex);
						++SellRamyeonCount;
					}
						break;
					case ksw::ECookType::Atomic:
						++AtomicSellRamyeonCount;
						break;
					}
					
					//std::cout << SellRamyeonCount << std::endl;
					//printf_s("Thread %x : %lu \n", ID, SellRamyeonCount);
				}
			};

		std::mutex Mutex;
		size_t JobCount = RamyeonCount / StoveCount;
		
		Stove.reserve(StoveCount);
		for (size_t i = 0; i < StoveCount; i++)
		{
			std::thread* NewStove = new std::thread(MakeRamyeon, JobCount, std::ref(Mutex), _CookType);
			Stove.push_back(NewStove);
		}

		for (size_t i = 0; i < Stove.size(); i++)
		{
			Stove[i]->join();
			delete Stove[i];
		}

		Stove.clear();

		AfterInfo(_CookType);
	}

	void RamyeonStore::BeforeInfo()
	{
		std::cout << "\n** SW_Ramyeon **" << std::endl;
		std::cout << "목표 판매량 : " << RamyeonCount << std::endl;
		std::cout << std::endl;
	}

	void RamyeonStore::AfterInfo(ECookType _CookType)
	{
		switch (_CookType)
		{
		case ksw::ECookType::Mutex:
			std::cout << "영업 후 판매 수 : " << SellRamyeonCount << std::endl;
			std::cout << "오차 : " << RamyeonCount - SellRamyeonCount << std::endl;
			break;
		case ksw::ECookType::Atomic:
			std::cout << "영업 후 판매 수 : " << AtomicSellRamyeonCount << std::endl;
			std::cout << "오차 : " << RamyeonCount - AtomicSellRamyeonCount << std::endl;
			break;
		}
		std::cout << std::endl;
	}
}
