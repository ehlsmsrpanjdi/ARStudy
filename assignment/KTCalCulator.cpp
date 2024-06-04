#include "PreCompile.h"
#include "KTCalCulator.h"

KTCalCulator::KTCalCulator()
{
}

KTCalCulator::~KTCalCulator()
{
}
void KTCalCulator::Start()
{
	//Operator('+', [=]
	//
	//	{
	//	}
	//);
	switch (Operator)
	{
	case'+':
		Result = Num1 + Num2;
		break;
	case'-':
		Result = Num1 - Num2;
		break;
	case'*':
		Result = Num1 * Num2;
		break;
	case'/':
		Result = Num1 / Num2;
		break;
	default:
		break;
	}

	
	
	
}