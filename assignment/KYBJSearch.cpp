#include "PreCompile.h"

#include "KYBJSearch.h"

KYBJSearch::KYBJSearch()
{
}

KYBJSearch::~KYBJSearch()
{
}

#include <iostream>
#include <vector>
#include <queue>

void KYBJSearch::BFS1926(int _X, int _Y)
{
	DataCheck[_Y][_X] = true;
	++LocalArea;
	q.pop();

	for (size_t i = 0; i < CheckDir.size(); i++)
	{
		int Y = _Y + CheckDir[i].y;
		int X = _X + CheckDir[i].x;

		if (Y < 0 || X < 0 || Y >= Row || X >= Col)
		{
			continue;
		}

		if (1 == Datas[Y][X] && false == DataCheck[Y][X])
		{
			DataCheck[Y][X] = true;
			q.push({ X , Y });
		}
	}

	while (!q.empty())
	{
		POINT Pos = q.front();

		BFS1926(Pos.x, Pos.y);
	}
}

void KYBJSearch::BJ1926()
{
	std::cin >> Row;
	std::cin >> Col;

	Datas.resize(Row);
	DataCheck.resize(Row);

	for (int i = 0; i < Row; i++)
	{
		Datas[i].resize(Col);
		DataCheck[i].resize(Col);
	}

	int InputValue = -1;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			std::cin >> InputValue;
			Datas[i][j] = InputValue;
			DataCheck[i][j] = false;
		}
	}

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (true == DataCheck[i][j] || 0 == Datas[i][j])
			{
				continue;
			}
			
			if (1 == Datas[i][j])
			{
				++PicCount;
				q.push({ i , j });
				BFS1926(j, i);

				if (LocalArea > MaxArea)
				{
					MaxArea = LocalArea;
				}

				LocalArea = 0;
			}
		}
	}

	std::cout << PicCount << std::endl;
	std::cout << MaxArea << std::endl;
}