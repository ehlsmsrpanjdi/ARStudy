#pragma once
class JWBJSerach
{
public:
	JWBJSerach();
	~JWBJSerach();

	JWBJSerach(const JWBJSerach& _Other) = delete;
	JWBJSerach(JWBJSerach&& _Other) noexcept = delete;
	JWBJSerach& operator=(const JWBJSerach& _Other) = delete;
	JWBJSerach& operator=(JWBJSerach&& _Other) noexcept = delete;


	void BJ1926();
	void BJ2178();

protected:
	void BFS1926(int Y, int X, int& Width);
	void BFS2178(int Y, int X);

private:
	std::queue<std::pair<int, int>> Que;
	std::vector<std::vector<int>> Graph;
	std::vector<std::vector<bool>> Visited;
	int CheckX[4] = { 1, 0, -1, 0 };
	int CheckY[4] = { 0, 1, 0, -1 };
	int n, m;
};

