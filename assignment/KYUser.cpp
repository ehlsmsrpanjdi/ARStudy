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
	std::cout << "������ �Է��ϼ���." << std::endl;
	std::cout << "���� : 1 + 2 * 3 - 4" << std::endl;
	std::cout << "���� : ";

	std::string CalString = "None";
	std::cin >> CalString;
	
	KYCalculator Calculator = KYCalculator(CalString);
}