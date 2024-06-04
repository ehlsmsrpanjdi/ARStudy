#include "PreCompile.h"

#include "KYCalculator.h"

KYCalculator::KYCalculator()
{
}

KYCalculator::KYCalculator(std::string_view _CalString)
	:CalString(_CalString)
{
	int Idx = 0;
	while (0 != CalString[Idx])
	{
		if ('0' <= CalString[Idx] && '9' >= CalString[Idx])
		{
			CalNum.push_back(CalString[Idx] - '0');
		}

		if ('+' == CalString[Idx]
			|| '-' == CalString[Idx])
		{
			CalOperator.push_back(CalString[Idx]);
		}

		++Idx;
	}


	Operator['+'] = [=](int Left, int Right)->int
		{
			int Result = Left + Right;
			return Result;
		};

	Operator['-'] = [=](int Left, int Right)->int
		{
			int Result = Left - Right;
			return Result;
		};


	{
		int Result = 0; 

		if (true != Operator.contains(CalOperator[0]))
		{
			MsgBoxAssert("정상적으로 등록되지 않은 연산자가 있습니다." + CalOperator[0]);
			return;
		}

		Result = Operator[CalOperator[0]](CalNum[0], CalNum[1]);

		std::cout << Result << std::endl;
	}
}


KYCalculator::~KYCalculator()
{
}

