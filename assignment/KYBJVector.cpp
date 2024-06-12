﻿#include "PreCompile.h"

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

//#include <iostream>
//#include <string>
//#include <vector>

void KYBJVector::BJ1919()
{
	std::string LeftStr = std::string();
	std::string RightStr = std::string();

	std::cin >> LeftStr;
	std::cin >> RightStr;

	std::vector<int> LeftStrVec = std::vector<int>();
	std::vector<int> RightStrVec = std::vector<int>();
	int StrVecSize = 'z' - 'a' + 1;
	int RemoveCharNum = 0;

	LeftStrVec.resize(StrVecSize);
	RightStrVec.resize(StrVecSize);

	for (size_t i = 0; i < LeftStr.size(); i++)
	{
		++LeftStrVec[LeftStr[i] - 'a'];
	}

	for (size_t i = 0; i < RightStr.size(); i++)
	{
		++RightStrVec[RightStr[i] - 'a'];
	}


	for (int i = 0; i < StrVecSize; i++)
	{
		while (LeftStrVec[i] != RightStrVec[i])
		{
			if (LeftStrVec[i] < RightStrVec[i])
			{
				--RightStrVec[i];
			}
			else if (LeftStrVec[i] > RightStrVec[i])
			{
				--LeftStrVec[i];
			}
			++RemoveCharNum;
		}
	}

	std::cout << RemoveCharNum;
}