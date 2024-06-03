#include "PreCompile.h"
#include "JWUser.h"
#include <iostream>
#include <functional>

JWUser::JWUser()
{
	Cal.Start();
}

JWUser::~JWUser()
{
	IsFirstTime = true;
}

void JWUser::CalStart()
{
	int FirstNumber;
	std::cin >> FirstNumber;
	if (true == IsFirstTime)
	{
		IsFirstTime = false;
		FirstSet(FirstNumber);
	}
	while (true)
	{
		char Orders;
		int Number;
		std::cin >> Orders;
		if (Orders == 'e')
		{
			break;
		}
		std::cin >> Number;
		float Result = Calculate(Number, Orders);
		std::cout << Result << std::endl;
	}
}

float JWUser::Calculate(float _Number, char _Orders)
{
	return Cal.Order[_Orders](_Number);
}

void JWUser::FirstSet(float _Number)
{
	Cal.SetFirst(_Number);
}

