#include "PreCompile.h"

#include "KYBJVector.h"

KYBJVector::KYBJVector()
{
}

KYBJVector::~KYBJVector()
{
}

void KYBJVector::BJ10808()
{
	std::string InputStr = std::string();
	std::cin >> InputStr;

	std::vector<int> Alphabets = std::vector<int>();

	int ResizeVal = static_cast<int>('z' - 'a') + 1;

	Alphabets.resize(ResizeVal);

	for (int i = 0; i < InputStr.size(); i++)
	{
		++Alphabets[InputStr[i] - static_cast<int>('a')];
	}

	for (int i = 0; i < Alphabets.size(); i++)
	{
		std::cout << Alphabets[i];
		std::cout << " ";
	}
}

//#include <iostream>
//#include <string>
//#include <cmath>
//#include <vector>

void KYBJVector::BJ1475()
{
	std::vector<int> EachNumbers = std::vector<int>();
	EachNumbers.resize(10);

	int MaxNumber = 0;

	std::string RoomNumber = std::string();
	std::cin >> RoomNumber;

	for (size_t i = 0; i < RoomNumber.size(); i++)
	{
		++EachNumbers[RoomNumber[i] - static_cast<int>('0')];
	}

	for (int i = 0; i < 10; i++)
	{
		if (6 == i || 9 == i)
		{
			float CeilNum = (static_cast<float>(EachNumbers[6]) + static_cast<float>(EachNumbers[9])) / 2.0f;
			int DuplicateNum = static_cast<int>(ceil(CeilNum));

			if (DuplicateNum > MaxNumber)
			{
				MaxNumber = DuplicateNum;
			}
			continue;
		}

		if (EachNumbers[i] > MaxNumber)
		{
			MaxNumber = EachNumbers[i];
		}
	}

	std::cout << MaxNumber;;
}