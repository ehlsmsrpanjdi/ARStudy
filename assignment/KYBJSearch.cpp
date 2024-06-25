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

void KYBJSearch::BFS1926()
{

}

void KYBJSearch::BJ1926()
{
	int Row = -1;
	int Col = -1;
	std::vector<std::vector<int>> Datas = std::vector<std::vector<int>>();

	std::cin >> Row;
	std::cin >> Col;


	Datas.resize(Row);
	for (int i = 0; i < Row; i++)
	{
		Datas[i].resize(Col);
	}

	int Value = -1;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			std::cin >> Value;
			Datas[i][j] = Value;
		}
	}

}