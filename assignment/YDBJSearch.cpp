#include "PreCompile.h"
#include "YDBJSearch.h"
#include <iostream>
#include <queue>

YDBJSearch::YDBJSearch()
{
}

YDBJSearch::~YDBJSearch()
{
}

int paper[500][500] = { 0, };
bool visited[500][500] = { false, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n = 0, m = 0;

int bfs(int x, int y)
{
	std::queue<std::pair<int, int>> Q;
	int mymax = 0;

	Q.push(std::make_pair(x, y));
	visited[x][y] = true;

	while (!Q.empty())
	{
		++mymax;
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (1 != paper[nx][ny] || nx < 0 || ny < 0 || nx >= n || ny >= m || true == visited[nx][ny]) continue;
			if (0 == visited[nx][ny])
			{
				Q.push(std::make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	return mymax;
}

void YDBJSearch::BJ1926()
{
	int tmp = 0, count = 0, maxwidth = 0;
	std::cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> tmp;
			if (1 == tmp)
			{
				paper[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (paper[i][j] == 1 && visited[i][j] == false)
			{
				int thismax = bfs(i, j);
				if (thismax > maxwidth)
				{
					maxwidth = thismax;
				}
				++count;
			}
		}
	}

	std::cout << count << '\n';
	std::cout << maxwidth;
}

void YDBJSearch::BJ2178()
{
	int N, M;
	int graph[100][100] = { 0, };
	int visited[100][100] = { 0, };
	std::queue<std::pair<int, int>> Q;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1,-1,0,0 };


	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::string row;
		std::cin >> row;

		for (int j = 0; j < M; ++j)
		{
			if (row[j] == '1')
			{
				graph[i][j] = 1;
			}
		}
	}

	Q.push(std::make_pair(0, 0));
	visited[0][0] = 1;
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 == graph[nx][ny] || 0 < visited[nx][ny] || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			Q.push(std::make_pair(nx, ny));
			visited[nx][ny] = visited[x][y] + 1;
		}
	}


	std::cout << visited[N - 1][M - 1];
}