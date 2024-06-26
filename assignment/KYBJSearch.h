#pragma once

// Ό³Έν :
class KYBJSearch
{
public:
	// constrcuter destructer
	KYBJSearch();
	~KYBJSearch();

	void BFS1926(int _X, int _Y);
	void BJ1926();
	void BJ2178();
	void BFS2178(int _Y, int _X);
	void Softeer1();
	void ST1BPS(std::vector<std::pair<int, int>> _FriendPos);

protected:

private:
	int Row = -1;
	int Col = -1;
	std::vector<std::vector<int>> Datas = std::vector<std::vector<int>>();
	std::vector<std::vector<bool>> DataCheck = std::vector<std::vector<bool>>();
	std::queue<std::pair<int, int>> q = std::queue<std::pair<int, int>>();

	std::vector<int> CheckDirX = { 1, 0, -1, 0 };
	std::vector<int> CheckDirY = { 0, 1, 0, -1 };

	int PicCount = 0;
	int LocalArea = 0;
	int MaxArea = 0;
};