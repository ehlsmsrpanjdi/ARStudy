#include "PreCompile.h"

#include "KYRamyeon.h"
#include <thread>

KYRamyeon::KYRamyeon()
{
}

KYRamyeon::~KYRamyeon()
{
	if (true == Function1.joinable())
	{
		Function1.join();
	}
}

void KYRamyeon::TestFunction()
{
	for (int i = 0; i < RamenNum; i++)
	{
		++CookingCount;
	}
}

void KYRamyeon::CookingStart()
{
	if (-1 == GasRangeNum || -1 == RamenNum)
	{
		MsgBoxAssert("주문 세팅값을 정상적으로 지정하지 않았습니다. 확인해주세요.");
		return;
	}

	Function1 = std::thread(std::bind(&KYRamyeon::TestFunction, this));

	Function1;

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

	for (int i = 0; i < _GasRangeNum; i++)
	{
		//CookingThread[i] = [this]()
		//	{
		//		int a = 0;
		//	};
	}
}