#pragma once
#include <iostream>
#include "YDCalculator.h"


template<typename Type>
class YDUser
{
public:
	YDUser()
	{
		MyCal = new YDCalculator<Type>();
	}
	~YDUser()
	{
		delete MyCal;
		MyCal = nullptr;
	}

	YDUser(const YDUser& _Other) = delete;
	YDUser(YDUser&& _Other) noexcept = delete;
	YDUser& operator=(const YDUser& _Other) = delete;
	YDUser& operator=(YDUser&& _Other) noexcept = delete;

	Type InputExpression(Type _Left, char _op, Type _Right)
	{
		switch (_op)
		{
		case '+':
		{
			MyCal->MyFunc = [=](Type Left, Type Right) -> Type
				{
					return Left + Right;
				};
		}
		break;
		case '-':
		{
			MyCal->MyFunc = [=](Type Left, Type Right) -> Type
				{
					return Left - Right;
				};
		}
		break;
		case '*':
		{
			MyCal->MyFunc = [=](Type Left, Type Right) -> Type
				{
					return Left * Right;
				};
		}
		break;
		case '/':
		{
			MyCal->MyFunc = [=](Type Left, Type Right) -> Type
				{
					if (Right == 0)
					{
						return static_cast<Type>(0);
					}
					return Left / Right;
				};
		}
		break;
		case '%':
		{
			MyCal->MyFunc = [=](Type Left, Type Right) -> Type
				{
					if (Right == 0)
					{
						return static_cast<Type>(0);
					}
					return Left % Right;
				};
		}
		break;
		default:
			break;
		}

		return MyCal->MyFunc(_Left, _Right);
	}
protected:


private:
	YDCalculator<Type>* MyCal = nullptr;
};
