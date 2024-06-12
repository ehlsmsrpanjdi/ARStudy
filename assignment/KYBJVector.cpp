#include "PreCompile.h"

#include "KYBJVector.h"

KYBJVector::KYBJVector()
{
}

KYBJVector::~KYBJVector()
{
}

void KYBJVector::BJ10808()
{
	std::string InputStr = std::string();
	std::cin >> InputStr;

	std::vector<int> Alphabets = std::vector<int>();

	int ResizeVal = static_cast<int>('z' - 'a') + 1;

	Alphabets.resize(ResizeVal);

	for (int i = 0; i < InputStr.size(); i++)
	{
		++Alphabets[InputStr[i] - static_cast<int>('a')];
	}

	for (int i = 0; i < Alphabets.size(); i++)
	{
		std::cout << Alphabets[i];
		std::cout << " ";
	}
}