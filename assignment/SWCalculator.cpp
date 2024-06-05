#include "PreCompile.h"
#include "SWCalculator.h"

namespace ksw
{
	calculator::calculator()
	{
		Init();
	}

	calculator::~calculator()
	{
	}
	
	void calculator::Start()
	{



		// 실행
		while (true)
		{
			std::string Input = "";
			std::getline(std::cin, Input);






			// 출력
			std::cout << Temp << std::endl;
		}
	}

	void calculator::Init()
	{
		GetPriority = [=](char _Input)->int
			{
				ESymbol Input = static_cast<ESymbol>(_Input);

				if (ESymbol::L_PARENTHESIS == Input)
				{
					return 0;
				}

				if (ESymbol::PLUS == Input || ESymbol::MINUS == Input)
				{
					return 1;
				}

				if (ESymbol::MUL == Input || ESymbol::DIV == Input)
				{
					return 2;
				}

				if (ESymbol::SPACE == Input)
				{
					return 3;
				}

				MsgBoxAssert("잘못된 입력입니다.");
				return -1;
			};

		Operator[static_cast<int>(ESymbol::PLUS)]	= [=](float _Num) { Temp += _Num; };
		Operator[static_cast<int>(ESymbol::MINUS)]	= [=](float _Num) { Temp -= _Num; };
		Operator[static_cast<int>(ESymbol::MUL)]	= [=](float _Num) { Temp *= _Num; };
		Operator[static_cast<int>(ESymbol::DIV)]	= [=](float _Num) { Temp /= _Num; };
	}
}
