#include "PreCompile.h"
#include "JYBJSearch.h"

#include <iostream>

JYBJSearch::JYBJSearch()
{

}

JYBJSearch::~JYBJSearch()
{

}

int BJ1926()
{
	return 0;
}

int BJ2178()
{
	int n, m;
	std::string row;
	int map[100][100] = { 0, };
	bool visited[100][100] = { false, };
	int distance[100][100] = { 0, };
	//std::queue<>

	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		std::cin >> row;

		for (int j = 0; j < m; j++)
		{
			map[i][j] = row[j] - 48;
		}
	}



	return 0;
}