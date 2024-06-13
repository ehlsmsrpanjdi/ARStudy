#include "PreCompile.h"
#include "YDBJVector.h"
#include <vector>
#include <iostream>

YDBJVector::YDBJVector()
{
}

YDBJVector::~YDBJVector()
{
}

void YDBJVector::BJ10808()
{
	std::vector<int> alpha;
	std::string word = "";

	std::cin >> word;

	alpha.resize(26);
	for (int i = 0; i < word.size(); i++)
	{
		char c = word[i];
		++alpha[c - 'a'];
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << alpha[i] << " ";
	}
}

void YDBJVector::BJ2577()
{
	std::vector<int> nums;
	int A, B, C;

	std::cin >> A >> B >> C;
	int result = A * B * C;

	nums.resize(10);

	while (result > 0)
	{
		++nums[result % 10];
		result = result / 10;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << nums[i] << '\n';
	}
}