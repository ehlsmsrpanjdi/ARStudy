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
	std::cin >> n;
	std::cin >> m;

	Graph.resize(n);
	Visited.resize(n);
	for (int Y = 0; Y < n; Y++)
	{
		Graph[Y].resize(m);
		Visited[Y].resize(m, false);
		for (int X = 0; X < m; X++)
		{
			std::cin >> Graph[Y][X];
		}
	}

	int Count = 0;
	int Width = 0;
	int MaxWidth = 0;

	for (int Y = 0; Y < n; Y++)
	{
		for (int X = 0; X < m; X++)
		{
			if (1 == Graph[Y][X] && false == Visited[Y][X])
			{
				Count++;
				Width = 0;
				BFS1926(Y, X, Width);
				if (Width > MaxWidth)
				{
					MaxWidth = Width;
				}
			}
		}
	}

	std::cout << Count << std::endl;
	std::cout << MaxWidth << std::endl;
}

void JWBJSerach::BJ2178()
{
	std::cin >> n;
	std::cin >> m;

	Graph.resize(n);
	Visited.resize(n);

	for (int Y = 0; Y < n; Y++)
	{
		std::string Line;
		Graph[Y].resize(m);
		Visited[Y].resize(m, false);
		std::cin >> Line;
		for (int X = 0; X < m; X++)
		{
			int Number = Line[X] - '0';
			Graph[Y][X] = Number;
		}
	}

	BFS(0, 0);
	return 0;
}

void JWBJSerach::BFS1926(int Y, int X, int& Width)
{
	Visited[Y][X] = true;
	Que.push(std::make_pair(Y, X));
	Width++;

	while (true != Que.empty())
	{
		Y = Que.front().first;
		X = Que.front().second;
		Que.pop();

		for (int i = 0; i < 4; i++)
		{
			int NextX = X + CheckX[i];
			int NextY = Y + CheckY[i];

			if (NextY < 0 || NextY >= n || NextX < 0 || NextX >= m)
			{
				continue;
			}
			if (1 == Graph[NextY][NextX] && false == Visited[NextY][NextX])
			{
				Visited[NextY][NextX] = true;
				Que.push(std::make_pair(NextY, NextX));
				Width++;
			}
		}
	}
}

void JWBJSerach::BFS2178(int Y, int X)
{
	std::vector<std::vector<int>> Dist;
	Dist.resize(n);
	for (int Y = 0; Y < n; Y++)
	{
		Dist[Y].resize(m, 0);
	}

	// 초기 세팅
	Visited[Y][X] = true;
	Que.push(std::make_pair(Y, X));
	Dist[Y][X]++;

	// BFS 탐색 시작
	while (true != Que.empty())
	{
		Y = Que.front().first;
		X = Que.front().second;
		Que.pop();

		for (int i = 0; i < 4; i++)
		{
			int NextX = X + CheckX[i];
			int NextY = Y + CheckY[i];

			if (NextY < 0 || NextY >= n || NextX < 0 || NextX >= m)
			{
				continue;
			}
			if (1 == Graph[NextY][NextX] && false == Visited[NextY][NextX])
			{
				Visited[NextY][NextX] = true;
				Que.push(std::make_pair(NextY, NextX));
				Dist[NextY][NextX] = Dist[Y][X] + 1;
			}
		}
	}

	std::cout << Dist[n - 1][m - 1] << std::endl;
}
