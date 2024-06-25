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

protected:

private:
	int Row = -1;
	int Col = -1;
	std::vector<std::vector<int>> Datas = std::vector<std::vector<int>>();
	std::vector<std::vector<bool>> DataCheck = std::vector<std::vector<bool>>();
	std::queue<POINT> q = std::queue<POINT>();

	std::vector<POINT> CheckDir = { {1, 0},{0,1},{-1,0},{0,-1} };

	int PicCount = 0;
	int LocalArea = 0;
	int MaxArea = 0;
};