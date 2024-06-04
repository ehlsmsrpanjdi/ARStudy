#include "PreCompile.h"

#include "KYUser.h"
#include "KYCalculator.h"

KYUser::KYUser()
{
}

KYUser::~KYUser()
{
}

void KYUser::CalculateBegin()
{
	std::cout << "계산식을 입력하세요." << std::endl;
	std::cout << "예시 : 1 + 2 * 3 - 4" << std::endl;
	std::cout << "계산식 : ";

	std::string CalString = "None";
	std::cin >> CalString;
	
	KYCalculator Calculator = KYCalculator(CalString);
}