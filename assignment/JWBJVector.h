#pragma once
class JWBJVector
{
public:
	JWBJVector();
	~JWBJVector();

	JWBJVector(const JWBJVector& _Other) = delete;
	JWBJVector(JWBJVector&& _Other) noexcept = delete;
	JWBJVector& operator=(const JWBJVector& _Other) = delete;
	JWBJVector& operator=(JWBJVector&& _Other) noexcept = delete;

	void BJ10808();
	void BJ2577();
	void BJ1475();
	void BJ3273();
	void BJ10807();
	void BJ13300();
	void BJ11328();
	void BJ1919();

	void BJ3273TwoPointer();

protected:

private:

};

