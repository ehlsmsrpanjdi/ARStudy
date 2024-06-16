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

//#include <iostream>
//#include <vector>

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
	int NumberOfRoom = 0;

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

	// 여자방
	for (int i = 0; i < 6; i++)
	{
		// 여자방 수 계산
		{
			// 방제한 수보다 학생 수가 더 많을 때
			while (true)
			{
				if (LimitNum >= GirlsRoom[i])
				{
					break;
				}

				// 2을 입력받았으면 0, 1, 2까지는 ㄱㅊ 3명부터가 문제
				if (LimitNum < GirlsRoom[i])
				{
					GirlsRoom[i] -= LimitNum;
					++NumberOfRoom;
				}
			}

			if (0 != GirlsRoom[i])
			{
				++NumberOfRoom;
			}
		}

		// 남자방 수 계산
		{
			while (true)
			{
				if (LimitNum >= BoysRoom[i])
				{
					break;
				}

				if (LimitNum < BoysRoom[i])
				{
					BoysRoom[i] -= LimitNum;
					++NumberOfRoom;
				}
			}

			if (0 != BoysRoom[i])
			{
				++NumberOfRoom;
			}
		}
	}

	std::cout << NumberOfRoom;
}

//#include <iostream>
//#include <vector>
//#include <string>

void KYBJVector::BJ11328()
{
	// strfry : 입력된 문자열을 재배열하는 함수
	// (즉, Src 문자열과 Dest문자열의 문자열을 각각 벡터에 집어넣고 각 배열 요소가 맞는지를 확인하면 될 것

	int CaseNum = -1;
	int CharNum = static_cast<int>('z' - 'a' + 1);
	std::vector<std::vector<int>> CheckSrcStrings = std::vector<std::vector<int>>();
	std::vector<std::vector<int>> CheckDstStrings = std::vector<std::vector<int>>();
	std::string SrcString = std::string();
	std::string DstString = std::string();


	std::cin >> CaseNum;
	


	CheckSrcStrings.resize(CaseNum);
	CheckDstStrings.resize(CaseNum);

	for (int i = 0; i < CaseNum; i++)
	{
		std::cin >> SrcString;
		std::cin >> DstString;

		CheckSrcStrings[i].resize(CharNum);
		CheckDstStrings[i].resize(CharNum);

		for (size_t j = 0; j < SrcString.size(); j++)
		{
			++CheckSrcStrings[i][SrcString[j] - 'a'];
		}

		for (size_t j = 0; j < DstString.size(); j++)
		{
			++CheckDstStrings[i][DstString[j] - 'a'];
		}
	}

	for (int i = 0; i < CaseNum; i++)
	{
		int j = 0;

		while (true)
		{
			if (j > static_cast<int>(CheckSrcStrings.size()))
			{
				break;
			}

			if (CheckSrcStrings[i][j] != CheckDstStrings[i][j])
			{
				std::cout << "Impossible" << std::endl;
				break;
			}
			++j;
		}

		if (j > static_cast<int>(CheckSrcStrings.size()))
		{
			std::cout << "Possible" << std::endl;
		}
	}
}

#include <iostream>
#include <vector>

void KYBJVector::BJ3273()
{
	// n개의 수 벡터에 저장
	//  (1 <= Ai <= 1000000) 의 범위의 서로다른 Ai들 n개가 저장된다
	// X를 입력 받으면 요소들 중 2개 합이 X가 되는 조합의 수를 찾을 것

	// 입력
	// 1. 수열 크기
	// 2. 수열 요소들 입력
	// 3. 더해서 X가 되는 조합
		
	int NumOfElements = -1;
	int Element = 0;
	std::vector<int> Elements = std::vector<int>();
	int SumValue = -1;
	int AvailableCalNum = 0;

	std::cin >> NumOfElements;
	Elements.reserve(NumOfElements);

	for (int i = 0; i < NumOfElements; i++)
	{
		std::cin >> Element;

		if (1 > Element || 1000000 < Element)
		{
			std::cout << "입력된 요소의 값이 지정된 범위(1 <= 입력 값 <= 1000000)를 벗어납니다." << std::endl;
			return;
		}

		Elements.emplace_back(Element);
	}

	std::cin >> SumValue;
	if (1 > SumValue || 2000000 < SumValue)
	{
		std::cout << "입력된 합의 값이 지정된 범위(1 <= 입력 값 <= 2000000)를 벗어납니다." << std::endl;
		return;
	}

	for (size_t i = 0; i < Elements.size(); i++)
	{
		for (size_t j = i+1; j < Elements.size(); j++)
		{
			if (SumValue == Elements[i] + Elements[j])
			{
				++AvailableCalNum;
			}
		}
	}

	std::cout << AvailableCalNum;
}
