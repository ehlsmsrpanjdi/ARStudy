#include "PreCompile.h"

#include "KYBJSearch.h"

KYBJSearch::KYBJSearch()
{
}

KYBJSearch::~KYBJSearch()
{
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <utility>

void KYBJSearch::BFS1926(int _X, int _Y)
{
	DataCheck[_Y][_X] = true;
	++LocalArea;
	q.pop();

	for (size_t i = 0; i < CheckDirX.size(); i++)
	{
		int Y = _Y + CheckDirY[i];
		int X = _X + CheckDirX[i];

		if (Y < 0 || X < 0 || Y >= Row || X >= Col)
		{
			continue;
		}

		if (1 == Datas[Y][X] && false == DataCheck[Y][X])
		{
			DataCheck[Y][X] = true;
			q.push(std::pair(X , Y));
		}
	}

	while (!q.empty())
	{
		std::pair<int,int> Pos = q.front();

		BFS1926(Pos.first, Pos.second);
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
				q.push(std::pair(i, j));
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




#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

int InputX = -1;
int InputY = -1;
std::string MapInput = "";
std::vector<std::vector<int>> Miro = std::vector<std::vector<int>>();
std::vector<std::vector<int>> Dists = std::vector<std::vector<int>>();
std::vector<std::vector<bool>> CheckMat = std::vector<std::vector<bool>>();
std::queue<std::pair<int, int>> q = std::queue<std::pair<int, int>>();
std::pair<int, int> StartPos = std::pair<int, int>(0, 0);
std::vector<int> CheckDirX = { 1, 0, -1, 0 };
std::vector<int> CheckDirY = { 0, 1, 0, -1 };


void KYBJSearch::BFS2178(int _Y, int _X)
{
	CheckMat[_Y][_X] = true;
	q.pop();

	for (size_t i = 0; i < CheckDirX.size(); i++)
	{
		int X = _X + CheckDirX[i];
		int Y = _Y + CheckDirY[i];

		if (X < 0 || Y < 0 || X >= InputX || Y >= InputY)
		{
			continue;
		}

		if (1 == Miro[Y][X] && false == CheckMat[Y][X])
		{
			Dists[Y][X] = Dists[_Y][_X] + 1;
			CheckMat[Y][X] = true;
			q.push(std::pair<int, int>(X, Y));
		}
	}

	while (!q.empty())
	{
		std::pair<int, int> NextPos = q.front();

		BFS2178(NextPos.second, NextPos.first);
	}
}

void KYBJSearch::BJ2178()
{
	std::cin >> InputY;
	std::cin >> InputX;

	Miro.resize(InputY);
	CheckMat.resize(InputY);
	Dists.resize(InputY);

	for (int i = 0; i < InputY; i++)
	{
		std::cin >> MapInput;
		
		Miro[i].resize(InputX);
		CheckMat[i].resize(InputX);
		Dists[i].resize(InputX);

		for (size_t j = 0; j < MapInput.size(); j++)
		{
			Miro[i][j] = MapInput[j] - '0';
			CheckMat[i][j] = false;
			Dists[i][j] = 0;
		}
	}

	++Dists[StartPos.second][StartPos.first];
	CheckMat[StartPos.second][StartPos.first] = true;
	q.push(std::pair<int, int>(StartPos.first, StartPos.second));
	BFS2178(StartPos.second, StartPos.first);

	std::cout << Dists[InputY - 1][InputX - 1];
}

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <set>

int MapN = -1;
int FriendNum = -1;
int Opportunity = 3;
int MaxFruitsCount = 0;
std::vector<std::vector<int>> Map = std::vector<std::vector<int>>();
std::vector<std::vector<bool>> Visited = std::vector<std::vector<bool>>();
std::vector<std::pair<int, int>> FriendPos = std::vector<std::pair<int, int>>();

std::vector<int> MoveX = { 1,0,-1,0 };
std::vector<int> MoveY = { 0,1,0,-1 };

std::vector<std::queue<std::pair<int, int>>> Queues = std::vector<std::queue<std::pair<int, int>>>();


void KYBJSearch::ST1BPS(std::vector<std::pair<int, int>> _FriendPos)
{
	std::pair<int, int> NextPos = std::pair<int, int>();
	int MaxFruitsNum = 0;
		
	for (int i = 0; i < FriendNum; ++i)
	{
		Queues[i].pop();
		Visited[_FriendPos[i].first][_FriendPos[i].second] = true;

		int X = -1;
		int Y = -1;

		for (size_t j = 0; j < MoveX.size(); j++)
		{
			X = _FriendPos[i].second + MoveX[j];
			Y = _FriendPos[i].first + MoveY[j];

			if (X < 0 || Y < 0 || X >= MapN || Y >= MapN)
			{
				continue;
			}

			if (MaxFruitsNum < Map[Y][X] && false == Visited[Y][X])
			{
				MaxFruitsNum = Map[Y][X];
				NextPos = std::pair<int, int>(Y, X);
			}
		}

		Visited[NextPos.first][NextPos.second] = true;
		int FruitsNum = Map[NextPos.first][NextPos.second];
		MaxFruitsCount += FruitsNum;

		Queues[i].push(NextPos);
		
		FriendPos[i] = Queues[i].front();

		NextPos = std::pair<int, int>(0, 0);
		MaxFruitsNum = 0;
	}

	while (0 < --Opportunity)
	{
		ST1BPS(FriendPos);
	}
}


void KYBJSearch::Softeer1()
{
	int InputVal = 0;
	int InputPosX = 0;
	int InputPosY = 0;

	std::cin >> MapN;
	std::cin >> FriendNum;

	Map.resize(MapN);
	Visited.resize(MapN);

	for (int i = 0; i < MapN; ++i)
	{
		Map[i].resize(MapN);
		Visited[i].resize(MapN);

		for (int j = 0; j < MapN; j++)
		{
			std::cin >> InputVal;
			Map[i][j] = InputVal;
			Visited[i][j] = false;
		}
	}

	for (int i = 0; i < FriendNum; ++i)
	{
		std::cin >> InputPosX;
		std::cin >> InputPosY;
		
		FriendPos.push_back(std::pair<int, int>(InputPosX - 1, InputPosY - 1));
		Queues.push_back(std::queue<std::pair<int, int>>());
		Queues[i].push(std::pair<int, int>(InputPosX - 1, InputPosY - 1));

		MaxFruitsCount += Map[InputPosX - 1][InputPosY - 1];
	}

	ST1BPS(FriendPos);

	std::cout << MaxFruitsCount;
}