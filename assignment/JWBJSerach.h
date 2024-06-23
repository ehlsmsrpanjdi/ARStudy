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

private:
	void CountPicture(std::vector<std::vector<int>> _Picture, int& _PCount, int& _MaxSize);
};

