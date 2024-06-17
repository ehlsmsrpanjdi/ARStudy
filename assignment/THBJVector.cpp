#include "PreCompile.h"
#include "THBJVector.h"

namespace lth
{
	THBJVector::THBJVector()
	{
	}

	THBJVector::~THBJVector()
	{
	}

	void THBJVector::BJ_10808()
	{
		std::string S = "";
		std::cin >> S;

		//Vector
		std::vector<int> Counts(26);
		for (int i = 0; i < S.size(); i++)
		{
			Counts[S[i] - 'a']++;
		}

		for (int i = 0; i < Counts.size(); i++)
		{
			std::cout << Counts[i] << " ";
		}

		// Array
		//int Counts[26] = {};
		//for (int i = 0; i < S.size(); i++)
		//{
		//	Counts[S[i] - 'a']++;
		//}

		//for (int i = 0; i < sizeof(Counts) / sizeof(int); i++)
		//{
		//	std::cout << Counts[i] << " ";
		//}
	}

	void THBJVector::BJ_2577()
	{
		int A;
		int B;
		int C;

		std::cin >> A;
		std::cin >> B;
		std::cin >> C;

		int Result = A * B * C;

		std::vector<int> Count(10, 0);

		while (Result > 0)
		{
			Count[Result % 10]++;
			Result /= 10;
		}

		for (int i = 0; i < 10; i++)
		{
			std::cout << Count[i] << std::endl;
		}
	}

	void THBJVector::BJ_1475()
	{
		std::vector<int> Counts(10, 0);
		std::vector<int>::iterator iter;
		int N;
		int Output = 0;

		std::cin >> N;
		while (N > 0)
		{
			int Result = N % 10;

			if (Result == 6 || Result == 9)
			{
				Counts[6] += 1;
			}
			else
			{
				Counts[Result] += 2;
			}

			N /= 10;
		}

		for (iter = Counts.begin(); iter != Counts.end(); iter++)
		{
			if (Output < *iter)
			{
				Output = *iter;
			}
		}

		if (Output % 2 != 0)
		{
			Output += 1;
		}

		std::cout << Output / 2;
	}

	void THBJVector::BJ_3273()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);

		int n;
		std::vector<int> NumberSequence;

		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			int input;
			std::cin >> input;
			NumberSequence.push_back(input);
		}
		std::sort(NumberSequence.begin(), NumberSequence.end());


		int x;
		std::cin >> x;
		int count = 0;
		int sum = 0;
		int low = 0;
		int high = n - 1;

		while (low < high)
		{
			sum = NumberSequence[low] + NumberSequence[high];
			if (sum > x)
			{
				high--;
			}
			else if (sum < x)
			{
				low++;
			}
			else
			{
				count++;
				high--;
				low++;
			}
		}

		std::cout << count;
	}

	void THBJVector::BJ_10807()
	{
		int N;
		int v;
		std::vector<int> Vector;
		std::vector<int>::iterator iter;
		int count = 0;

		std::cin >> N;

		for (int i = 0; i < N; i++)
		{
			int input;
			std::cin >> input;
			Vector.push_back(input);
		}

		std::cin >> v;

		for (iter = Vector.begin(); iter != Vector.end(); iter++)
		{
			if (*iter == v)
			{
				count++;
			}
		}

		std::cout << count;
	}

	void THBJVector::BJ_13300()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);

		int n, k;

		std::cin >> n >> k;

		std::vector<std::vector<int>> Students(6, std::vector<int>(2, 0));


		// resize() »ç¿ë
		//std::vector<std::vector<int>> Students;
		//Students.resize(6);
		//for (int i = 0; i < 6; ++i)
		//{
		//	Students[i].resize(2, 0);
		//}

		for (int i = 0; i < n; i++)
		{
			int s, y;
			std::cin >> s >> y;
			Students[y - 1][s]++;
		}

		int roomCount = 0;

		for (int i = 0; i < Students.size(); i++)
		{
			for (int j = 0; j < Students[i].size(); j++)
			{
				roomCount += Students[i][j] / k;
				if (Students[i][j] % k != 0)
				{
					roomCount++;
				}
			}
		}

		std::cout << roomCount;
	}

	void THBJVector::BJ_11328()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);

		std::string FirstString;
		std::string SecondString;
		int n;
		std::cin >> n;

		for (int i = 0; i < n; i++)
		{
			std::cin >> FirstString >> SecondString;

			std::sort(FirstString.begin(), FirstString.end());
			std::sort(SecondString.begin(), SecondString.end());
			if (FirstString == SecondString)
			{
				std::cout << "Possible" << std::endl;
			}
			else
			{
				std::cout << "Impossible" << std::endl;
			}
		}
	}

	void THBJVector::BJ_1919()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);

		std::vector<int> Alphabet1(26, 0);
		std::vector<int> Alphabet2(26, 0);

		std::string FirstWord;
		std::string SecondWord;

		std::cin >> FirstWord >> SecondWord;

		for (int i = 0; i < FirstWord.size(); i++)
		{
			Alphabet1[FirstWord[i] - 'a']++;
		}

		for (int i = 0; i < SecondWord.size(); i++)
		{
			Alphabet2[SecondWord[i] - 'a']++;
		}

		int count = 0;
		for (int i = 0; i < 26; i++)
		{
			if (Alphabet1[i] != Alphabet2[i])
			{
				count += std::abs(Alphabet1[i] - Alphabet2[i]);
			}
		}

		std::cout << count;
	}
}