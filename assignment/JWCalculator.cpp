#include "PreCompile.h"
#include "JWCalculator.h"

JWCalculator::JWCalculator()
{
}

JWCalculator::~JWCalculator()
{
}

void JWCalculator::Start()
{
	Order['+'] = [=](float b)
		{
			ResultTemp = ResultTemp + b;
			return ResultTemp;
		};

	Order['-'] = [=](float b)
		{
			ResultTemp = ResultTemp - b;
			return ResultTemp;
		};

	Order['*'] = [=](float b)
		{
			ResultTemp = ResultTemp * b;
			return ResultTemp;
		};

	Order['/'] = [=](float b)
		{
			if (0.0f == b)
			{
				MsgBoxAssert("0으로 나눌 수 없습니다.");
			}
			ResultTemp = ResultTemp / b;
			return ResultTemp;
		};
}
