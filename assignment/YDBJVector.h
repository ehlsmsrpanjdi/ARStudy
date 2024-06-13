#pragma once
class YDBJVector
{
public:
	YDBJVector();
	~YDBJVector();

	YDBJVector(const YDBJVector& _Other) = delete;
	YDBJVector(YDBJVector&& _Other) noexcept = delete;
	YDBJVector& operator=(const YDBJVector& _Other) = delete;
	YDBJVector& operator=(YDBJVector&& _Other) noexcept = delete;

	void BJ10808();
	void BJ2577();
protected:

private:

};

