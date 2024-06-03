#pragma once
#include "JWCalculator.h"

class JWUser
{
public:
	JWUser();
	~JWUser();

	JWUser(const JWUser& _Other) = delete;
	JWUser(JWUser&& _Other) noexcept = delete;
	JWUser& operator=(const JWUser& _Other) = delete;
	JWUser& operator=(JWUser&& _Other) noexcept = delete;

	void CalStart();
	float Calculate(float _Number, char _Orders);
	void FirstSet(float _Number);

protected:

private:
	JWCalculator Cal;

	bool IsFirstTime = true;

};

