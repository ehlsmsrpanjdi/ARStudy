#include "PreCompile.h"

#include "KYRamyeon.h"

KYRamyeon::KYRamyeon()
{
}

KYRamyeon::~KYRamyeon()
{
}

void KYRamyeon::CookingStart()
{
	if (-1 == GasRangeNum || -1 == RamenNum)
	{
		MsgBoxAssert("주문 세팅값을 정상적으로 지정하지 않았습니다. 확인해주세요.");
		return;
	}

	int a = 0;
}

void KYRamyeon::OrderSetting(int _GasRangeNum, int _RamenNum)
{
	GasRangeNum = _GasRangeNum;
	RamenNum = _RamenNum;
}