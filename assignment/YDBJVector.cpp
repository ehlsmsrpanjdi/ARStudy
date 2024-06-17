#include "PreCompile.h"
#include "YDBJVector.h"
#include <vector>
#include <set>
#include <iostream>
#include <map>

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

void YDBJVector::BJ1475()
{
	std::vector<int> SetCount;
	int nums = 0, maxnum = -1;
	SetCount.resize(10);
	std::cin >> nums;

	while (nums != 0)
	{
		int n = nums % 10;
		if (n == 6 || n == 9)
		{
			if (maxnum > SetCount[6])	// 있는 세트로 해결 가능
			{
				++SetCount[6];
			}
			else if (maxnum > SetCount[9])	// 있는 세트로 해결 가능
			{
				++SetCount[9];
			}
			else if (maxnum <= SetCount[6]) // 새로운 세트 쓰기
			{
				++SetCount[6];
				maxnum = SetCount[6];
			}
		}
		else
		{
			if (maxnum <= SetCount[n]) // 새로운 세트 쓰기
			{
				++SetCount[n];
				maxnum = SetCount[n];
			}
			else if (maxnum > SetCount[n])	// 있는 세트로 해결 가능
			{
				++SetCount[n];
			}
		}


		nums /= 10;
	}

	std::cout << maxnum;
}

bool IsUsed[2000001] = { false, };	// 제출할 때도 전역변수로했음 (스택영역 너무 많이쓴다해서)
void YDBJVector::BJ3273()
{

	int N, X, count = 0;
	int half = 0, turn = 0;
	std::set<int> nums;
	std::vector<int> NumsVector;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;
		nums.insert(num);
	}
	for (auto num : nums)
	{
		NumsVector.push_back(num);
	}

	std::cin >> X;
	for (int i = 0; i < N; i++)
	{
		if (!IsUsed[NumsVector[i]] &&
			(X - NumsVector[i] > 0 && !IsUsed[X - NumsVector[i]]) &&
			X - NumsVector[i] != NumsVector[i] &&
			nums.find(X - NumsVector[i]) != nums.end())
		{
			++count;
			IsUsed[i] = true;
			IsUsed[X - NumsVector[i]] = true;
		}
	}

	std::cout << count;
}

void YDBJVector::BJ10807()
{
	std::map<int, int> CountMap;
	int N, v;
	std::cin >> N;
	while (N)
	{
		--N;
		int tmp;
		std::cin >> tmp;
		++CountMap[tmp];
	}
	std::cin >> v;
	std::cout << CountMap[v];
}

void YDBJVector::BJ13300()
{
	std::vector<std::vector<int>> students;
	students.resize(6);
	for (int i = 0; i < 6; i++) // 학년
	{
		for (int j = 0; j <= 1; j++) // 성별 0여, 1남
		{
			students[i].push_back(0);
		}
	}
	int N = 0, K = 0, S = 0, Y = 0, result = 0;
	std::cin >> N >> K;

	while (N)
	{
		--N;
		std::cin >> S >> Y;
		++students[Y - 1][S];
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			result += students[i][j] / K;
			if (students[i][j] % K != 0)
			{
				++result;
			}
		}
	}
	std::cout << result;
}

void YDBJVector::BJ11328()
{
	int N;
	std::string str1, str2;
	std::cin >> N;
	while (N)
	{
		std::map<char, int> str1map;
		std::map<char, int> str2map;
		std::cin >> str1 >> str2;

		for (int i = 0; i < str1.size(); i++)
		{
			++str1map[str1[i]];
		}
		for (int i = 0; i < str2.size(); i++)
		{
			++str2map[str2[i]];
		}

		bool IsPossible = true;
		for (int i = 0; i < str2.size(); i++)
		{
			if (str1map[str2[i]] != str2map[str2[i]])
			{
				IsPossible = false;
			}
		}
		if (IsPossible)
		{
			std::cout << "Possible\n";
		}
		else
		{
			std::cout << "Impossible\n";
		}
		--N;
	}
}

void YDBJVector::BJ1919()
{
	int arr1[26] = { 0, };
	int arr2[26] = { 0, };
	int result = 0;
	std::string str1, str2;
	std::cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); ++i)
	{
		++arr1[str1[i] - 'a'];
	}
	for (int i = 0; i < str2.size(); ++i)
	{
		++arr2[str2[i] - 'a'];
	}

	for (int i = 0; i < 26; ++i)
	{
		result += abs(arr1[i] - arr2[i]);
	}

	std::cout << result;
}