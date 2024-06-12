#include "PreCompile.h"
#include "SJBJVector.h"
#include <algorithm>
#include <set>

SJBJVector::SJBJVector()
{
}

SJBJVector::~SJBJVector()
{
}

void SJBJVector::BJ10808()
{
	std::vector<int> Counts;
	Counts.resize(26);

	std::string Text;
	std::cin >> Text;

	for (char c : Text)
	{
		++Counts[c - 'a'];
	}

	for (int i = 0; i < Counts.size() - 1; ++i)
	{
		std::cout << Counts[i] << ' ';
	}
	std::cout << Counts[Counts.size() - 1];
}

void SJBJVector::BJ2577()
{
	int Prod = 1;
	for (int i = 0; i < 3; ++i)
	{
		int Input = 0;
		std::cin >> Input;
		Prod *= Input;
	}

	std::vector<int> Counts;
	Counts.resize(10);

	while (Prod)
	{
		int Remainder = Prod % 10;
		++Counts[Remainder];
		Prod /= 10;
	}

	for (int i = 0; i < Counts.size(); ++i)
	{
		std::cout << Counts[i] << "\n";
	}
}

void SJBJVector::BJ1475()
{
	std::vector<int> Counts;
	Counts.resize(9);

	std::string Input;
	std::cin >> Input;

	for (char c : Input)
	{
		if (c == '9')
		{
			++Counts[6];
			continue;
		}

		++Counts[c - '0'];
	}
	++Counts[6];
	Counts[6] /= 2;

	int Max = *std::max_element(Counts.begin(), Counts.end());
	std::cout << Max;
}

void SJBJVector::BJ3273()
{
	std::vector<int> a;
	std::set<int> Checks;

	int n = 0;
	std::cin >> n;
	a.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int v = 0;
		std::cin >> v;
		Checks.insert(v);
		a[i] = v;
	}

	int x = 0;
	std::cin >> x;

	int Ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (Checks.end() != Checks.find(x - a[i]))
		{
			++Ans;
		}
	}
	std::cout << Ans / 2;
}

void SJBJVector::BJ10807()
{
	std::vector<int> Arr;

	int n = 0;
	std::cin >> n;
	Arr.resize(n);

	for (int i = 0; i < Arr.size(); ++i)
	{
		std::cin >> Arr[i];
	}

	int v = 0;
	std::cin >> v;

	int Ans = std::count(Arr.begin(), Arr.end(), v);
	std::cout << Ans;
}

void SJBJVector::BJ13300()
{
	std::vector<std::vector<int>> Counts;
	Counts.resize(2);
	Counts[0].resize(7);
	Counts[1].resize(7);

	int n = 0;
	std::cin >> n;

	int RoomSize = 0;
	std::cin >> RoomSize;

	for (int i = 0; i < n; ++i)
	{
		int S = 0;
		std::cin >> S;

		int Y = 0;
		std::cin >> Y;

		++Counts[S][Y];
	}

	int RoomCount = 0;
	for (int S = 0; S <= 1; ++S)
	{
		for (int Y = 1; Y <= 6; ++Y)
		{
			Counts[S][Y] += RoomSize - 1;
			RoomCount += Counts[S][Y] / RoomSize;
		}
	}

	std::cout << RoomCount;
}

void SJBJVector::BJ11328()
{
	int n = 0;
	std::cin >> n;

	std::vector<std::vector<int>> LeftCounts;
	std::vector<std::vector<int>> RightCounts;
	LeftCounts.resize(n);
	RightCounts.resize(n);

	for (int i = 0; i < n; ++i)
	{
		LeftCounts[i].resize(26);
		RightCounts[i].resize(26);

		std::string Left;
		std::cin >> Left;

		std::string Right;
		std::cin >> Right;

		for (char c : Left)
		{
			++LeftCounts[i][c - 'a'];
		}

		for (char c : Right)
		{
			++RightCounts[i][c - 'a'];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		bool Possible = true;
		for (int j = 0; j < 26; ++j)
		{
			if (LeftCounts[i][j] != RightCounts[i][j])
			{
				Possible = false;
				break;
			}
		}

		if (Possible)
		{
			std::cout << "Possible";
		}
		else
		{
			std::cout << "Impossible";
		}
		std::cout << "\n";
	}
}

void SJBJVector::BJ1919()
{
	std::string Left;
	std::string Right;

	std::cin >> Left;
	std::cin >> Right;

	std::vector<int> LeftCounts;
	std::vector<int> RightCounts;
	LeftCounts.resize(26);
	RightCounts.resize(26);

	for (char c : Left)
	{
		++LeftCounts[c - 'a'];
	}

	for (char c : Right)
	{
		++RightCounts[c - 'a'];
	}

	int Ans = 0;
	for (int i = 0; i < 26; ++i)
	{
		Ans += std::abs(LeftCounts[i] - RightCounts[i]);
	}

	std::cout << Ans;
}
