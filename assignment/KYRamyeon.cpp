#include "PreCompile.h"

#include "KYRamyeon.h"
#include <thread>

KYRamyeon::KYRamyeon()
{
}

KYRamyeon::~KYRamyeon()
{
	for (int i = 0; i < GasRangeNum; i++)
	{
		if (true == CookingThread[i].joinable())
		{
			CookingThread[i].join();
		}
	}
}

void KYRamyeon::CookingStart()
{
	if (-1 == GasRangeNum || -1 == RamenNum)
	{
		MsgBoxAssert("주문 세팅값을 정상적으로 지정하지 않았습니다. 확인해주세요.");
		return;
	}

	for (int i = 0; i < GasRangeNum; i++)
	{
		CookingThread[i];
	}

	while (true)
	{
		if (RamenNum == CookingCount)
		{
			break;
		}
	}

	std::cout << "조리 완료" << std::endl;
}

void KYRamyeon::OrderSetting(int _GasRangeNum, int _RamenNum)
{
	GasRangeNum = _GasRangeNum;
	RamenNum = _RamenNum;

	int DividedWorkNum = static_cast<int>(RamenNum / GasRangeNum);

	for (int i = 0; i < _GasRangeNum; i++)
	{
		CookingThread.push_back(std::thread(std::bind([this, DividedWorkNum]()
			{
				for (int i = 0; i < DividedWorkNum; i++)
				{
					++CookingCount;
				}
			})));
	}
}