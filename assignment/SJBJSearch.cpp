#include "PreCompile.h"
#include "SJBJSearch.h"
#include <iostream>
#include <vector>
#include <set>
#include <queue>

SJBJSearch::SJBJSearch()
{
}

SJBJSearch::~SJBJSearch()
{
}

// BJ1926
int R, C;
std::vector<std::vector<int>> board;
std::set<std::pair<int, int>> visited;
int area;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void SJBJSearch::BJ1926()
{
    std::cin >> R >> C;

    board.resize(R);
    for (int i = 0; i < R; ++i)
    {
        board[i].resize(C);
        for (int j = 0; j < C; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    int count = 0;
    int maxArea = 0;

    visited.clear();
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            // if visited, then pass
            if (visited.end() != visited.find({ i, j }))
            {
                continue;
            }

            if (board[i][j] == 0)
            {
                continue;
            }

            area = 0;
            visit(i, j);

            if (area > maxArea)
            {
                maxArea = area;
            }

            ++count;
        }
    }

    std::cout << count << "\n" << maxArea;
}

void SJBJSearch::visit(int x, int y)
{
    visited.insert({ x, y });
    ++area;

    for (int k = 0; k < 4; ++k)
    {
        int nx = x + dx[k], ny = y + dy[k];

        if (0 <= nx && nx < R && 0 <= ny && ny < C)
        {
            if (board[nx][ny] == 0)
            {
                continue;
            }

            if (visited.end() != visited.find({ nx, ny }))
            {
                continue;
            }

            visit(nx, ny);
        }
    }
}

void SJBJSearch::BJ2178()
{
    std::cin >> R >> C;

    board.resize(R);
    for (int i = 0; i < R; ++i)
    {
        board[i].resize(C);

        std::string col;
        std::cin >> col;

        for (int j = 0; j < C; ++j)
        {
            board[i][j] = col[j] - '0';
        }
    }

    std::vector<std::vector<int>> dist(R, std::vector<int>(C, -1));
    std::queue<std::pair<int, int>> queue;

    dist[0][0] = 1;
    queue.push({ 0, 0 });

    while (!queue.empty())
    {
        auto pair = queue.front();
        int x = pair.first, y = pair.second;

        queue.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < R && 0 <= ny && ny < C)
            {
                if (board[nx][ny] == 0)
                {
                    continue;
                }

                if (dist[nx][ny] != -1)
                {
                    continue;
                }

                dist[nx][ny] = dist[x][y] + 1;
                queue.push({ nx, ny });
            }
        }
    }

    std::cout << dist[R - 1][C - 1];
}
