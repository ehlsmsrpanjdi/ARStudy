#include "PreCompile.h"

#include "KYCalculator.h"

KYCalculator::KYCalculator()
{
}

KYCalculator::KYCalculator(std::string_view _CalString)
	:CalString(_CalString)
{
	std::cout << CalString << std::endl;
}


KYCalculator::~KYCalculator()
{
}

