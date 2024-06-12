#pragma once

class SJBJVector
{
public:
	SJBJVector();
	~SJBJVector();

	SJBJVector(const SJBJVector& _Other) = delete;
	SJBJVector(SJBJVector&& _Other) noexcept = delete;
	SJBJVector& operator=(const SJBJVector& _Other) = delete;
	SJBJVector& operator=(SJBJVector&& _Other) noexcept = delete;

	void BJ10808();
	void BJ2577();
	void BJ1475();
	void BJ3273();
	void BJ10807();
	void BJ13300();
	void BJ11328();
	void BJ1919();

protected:


private:


};

