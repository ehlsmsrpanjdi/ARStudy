#include "PreCompile.h"
#include "JWBJSerach.h"

JWBJSerach::JWBJSerach()
{
}

JWBJSerach::~JWBJSerach()
{
}

void JWBJSerach::BJ1926()
{
	// 실패
	// 왜?? 출력은 이상 없는데 (여러 출력 가능)
	int n;
	int m;
	std::cin >> n;
	std::cin >> m;

	int PCount = 0;
	int MaxSize = 0;

	std::vector<std::vector<int>> Picture;

	for (int y = 0; y < n; y++)
	{
		std::vector<int> Number;
		for (int x = 0; x < m; x++)
		{
			int Num;
			std::cin >> Num;
			Number.push_back(Num);
		}
		Picture.push_back(Number);
	}

	CountPicture(Picture, PCount, MaxSize);

	std::cout << PCount << std::endl;
	std::cout << MaxSize << std::endl;
}

void JWBJSerach::CountPicture(std::vector<std::vector<int>> _Picture, int& _PCount, int& _MaxSize)
{
	int Y = _Picture.size();
	int X = _Picture[0].size();

	std::vector<std::vector<bool>> CheckVec;
	CheckVec.resize(Y);
	for (int i = 0; i < Y; i++)
	{
		CheckVec[i].resize(X, false);
	}

	std::vector<std::vector<int>> PartVec;
	PartVec.resize(Y);
	for (int i = 0; i < Y; i++)
	{
		PartVec[i].resize(X);
	}

	int Part = 1;
	// 오른쪽, 아래 탐색
	int Count = 0;

	for (int y = 0; y < Y; y++)
	{
		bool Check = false;
		int TempX = 0;
		while (TempX < X)
		{
			if (1 == _Picture[y][TempX] && false == CheckVec[y][TempX])
			{
				Count++;
				// 왼쪽 확인
				int XIndex = TempX - 1;
				if (0 <= XIndex && 1 == _Picture[y][XIndex])
				{
					Part = PartVec[y][XIndex];
					Count--;
				}

				// 위쪽 확인
				int YIndex = y - 1;
				if (0 <= YIndex && 1 == _Picture[YIndex][TempX])
				{
					Part = PartVec[YIndex][TempX];
					Check = true;
				}

				PartVec[y][TempX] = Part;
				CheckVec[y][TempX] = true;
			}
			Part++;
			TempX++;

		}
		if (true == Check)
		{
			Count--;
		}
	}

	std::map<int, int> SizeMap;
	int Temp = 0;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			int Num = PartVec[y][x];
			if (0 != Num)
			{
				SizeMap[Num]++;
			}
		}
	}

	int MaxValue = 0;
	for (int i = 0; i < SizeMap.size(); i++)
	{
		if (MaxValue < SizeMap[i])
		{
			MaxValue = SizeMap[i];
		}
	}

	_MaxSize = MaxValue;
	_PCount = Count;
}
