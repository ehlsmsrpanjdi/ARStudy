#include "PreCompile.h"
#include "KTCalCulator.h"

KTCalCulator::KTCalCulator()
{
	
	Fun = [=](float _Num , float _Num2 , char _Operator) {
		
			

			switch (_Operator)
			{
			case'+':
				Result = _Num + _Num2;
				break;
			case'-':
				Result = _Num - _Num2;
				break;
			case'*':
				Result = _Num * _Num2;
				break;
			case'/':
				Result = _Num / _Num2;
				break;
			default:
				break;
			}

			std::cout << Result;

		};
}


KTCalCulator::~KTCalCulator()
{
}

void KTCalCulator::Input()
{
	float num1;
	float num2;
	char char1;

	std::cin >> num1 >> num2 >> char1;
	Fun(num1, num2, char1);

}
