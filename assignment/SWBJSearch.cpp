#include "PreCompile.h"
#include "SWBJSearch.h"

namespace ksw
{
	BOJ_Search::BOJ_Search()
	{
	}

	BOJ_Search::~BOJ_Search()
	{
	}

	void BOJ_Search::Problem_1926()
	{
		int n = 0, m = 0;
		std::cin >> n >> m;

		std::vector<std::vector<int>> Picture(n);
		int PictureCount = 0;
		int MaxPictureSize = 0;

		for (int y = 0; y < n; y++)
		{
			Picture[y].assign(m, 0);
			for (int x = 0; x < m; x++)
			{
				std::cin >> Picture[y][x];
			}
		}

		std::vector<int> dX = { 1, 0, -1, 0 }; // x 좌표 이동
		std::vector<int> dY = { 0, 1, 0, -1 }; // y 좌표 이동

		// BFS 함수
		std::function BFS = [&](int _StartY, int _StartX)
			{
				if (1 != Picture[_StartY][_StartX])
				{
					return;
				};

				Picture[_StartY][_StartX] = 0;
				++PictureCount;

				int PictureSize = 1;
				std::queue<std::pair<int, int>> Q;
				Q.push(std::make_pair(_StartY, _StartX));

				while (false == Q.empty())
				{
					int X = Q.front().second;
					int Y = Q.front().first;
					Q.pop();

					for (int i = 0; i < 4; i++)
					{
						int Next_X = X + dX[i];
						int Next_Y = Y + dY[i];

						if (0 <= Next_X && m > Next_X && 0 <= Next_Y && n > Next_Y
							&& 1 == Picture[Next_Y][Next_X])
						{
							Picture[Next_Y][Next_X] = 0;
							++PictureSize;
							Q.push(std::make_pair(Next_Y, Next_X));
						}
					}
				}

				if (MaxPictureSize < PictureSize)
				{
					MaxPictureSize = PictureSize;
				}
			};

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				BFS(y, x);
			}
		}

		std::cout << PictureCount << '\n' << MaxPictureSize;
	}

	void BOJ_Search::Problem_2178()
	{
		int N = 0, M = 0;
		std::cin >> N >> M;

		std::vector<std::string> Maze(N);
		std::vector<std::vector<int>> Dist;
		std::vector<std::vector<bool>> IsVisited;

		Dist.resize(N);
		IsVisited.resize(N);
		for (int i = 0; i < N; i++)
		{
			std::cin >> Maze[i];
			IsVisited[i].assign(M, false);
			Dist[i].assign(M, 0);
		}

		std::vector<int> dX = { 1, 0, -1, 0 }; // x 좌표 이동
		std::vector<int> dY = { 0, 1, 0, -1 }; // y 좌표 이동

		// BFS 함수
		std::function BFS = [&](int _StartY, int _StartX)
			{
				IsVisited[_StartY][_StartX] = true;

				std::queue<std::pair<int, int>> Q;
				Q.push(std::make_pair(_StartY, _StartX));

				while (false == Q.empty())
				{
					int X = Q.front().second;
					int Y = Q.front().first;
					Q.pop();

					for (int i = 0; i < 4; i++)
					{
						int Next_X = X + dX[i];
						int Next_Y = Y + dY[i];

						if (0 <= Next_X && M > Next_X && 0 <= Next_Y && N > Next_Y
							&& '1' == Maze[Next_Y][Next_X] && false == IsVisited[Next_Y][Next_X])
						{
							Dist[Next_Y][Next_X] = Dist[Y][X] + 1;
							IsVisited[Next_Y][Next_X] = true;
							Q.push(std::make_pair(Next_Y, Next_X));
						}
					}
				}
			};

		BFS(0, 0);
		std::cout << Dist[N - 1][M - 1] + 1 << '\n';
	}
}

