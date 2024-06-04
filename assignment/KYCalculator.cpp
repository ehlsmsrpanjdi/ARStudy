#include "PreCompile.h"

#include "KYCalculator.h"

KYCalculator::KYCalculator()
{
}

KYCalculator::KYCalculator(std::string_view _CalString)
	:CalString(_CalString)
{
	std::cout << CalString << std::endl;

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


}


KYCalculator::~KYCalculator()
{
}

