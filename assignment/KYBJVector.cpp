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

//#include <iostream>
//#include <string>
//#include <vector>

void KYBJVector::BJ2577()
{
	std::vector<int> Numbers = std::vector<int>();
	int InputVal = 0;
	int MulResultVal = 1;

	for (int i = 0; i < 3; i++)
	{
		std::cin >> InputVal;
		Numbers.push_back(InputVal);
	}

	for (size_t i = 0; i < Numbers.size(); i++)
	{
		MulResultVal *= Numbers[i];
	}

	std::string ResultStr = std::string();
	ResultStr = std::to_string(MulResultVal);

	std::vector<int> NumVals = std::vector<int>();
	NumVals.resize(10);

	for (size_t i = 0; i < ResultStr.size(); i++)
	{
		++NumVals[ResultStr[i] - '0'];
	}

	for (int i = 0; i < NumVals.size(); i++)
	{
		std::cout << NumVals[i] << std::endl;
	}
}

//#include <iostream>
//#include <vector>

void KYBJVector::BJ10807()
{
	int NumSize = -1;
	int Value = -1;
	int FindNumVal = -1;
	int FindNumCount = 0;
	std::vector<int> NumbersVec = std::vector<int>();

	std::cin >> NumSize;

	for (int i = 0; i < NumSize; i++)
	{
		std::cin >> Value;
		NumbersVec.push_back(Value);
	}

	std::cin >> FindNumVal;

	for (size_t i = 0; i < NumbersVec.size(); i++)
	{
		if (FindNumVal == NumbersVec[i])
		{
			++FindNumCount;
		}
	}

	std::cout << FindNumCount;
}

#include <iostream>
#include <vector>

void KYBJVector::BJ13300()
{
	// 조건
	// -	남녀 별로
	// -	같은 학년만 배정
	// -	방안에 최대 인원수 제한
	// 
	// 출력 : 필요한 최소 방의 수

	int NumOfStudents = -1;
	int LimitNum = -1;
	int Gender = -1;
	int Grade = -1;

	std::vector<int> GirlsRoom = std::vector<int>();
	std::vector<int> BoysRoom = std::vector<int>();
	GirlsRoom.resize(6);
	BoysRoom.resize(6);

	std::cin >> NumOfStudents;
	std::cin >> LimitNum;


	for (int i = 0; i < NumOfStudents; i++)
	{
		std::cin >> Gender;
		
		std::cin >> Grade;

		switch (Gender)
		{
		case 0:
		{
			++GirlsRoom[Grade - 1];
			break;
		}
		case 1:
		{
			++BoysRoom[Grade - 1];
			break;
		}
		default:
			break;
		}
	}
}