#include "PreCompile.h"
#include "SWBJVector.h"

namespace ksw 
{
	BOJ_vector::BOJ_vector()
	{
	}

	BOJ_vector::~BOJ_vector()
	{
	}

	void BOJ_vector::Problem_1475()
	{
		int N = 0;
		std::cin >> N;

		std::vector<int> NumVec(10, 0);
		while (0 != N)
		{
			++NumVec[N % 10];
			N /= 10;
		}

		NumVec[6] += NumVec[9];
		NumVec[6] = static_cast<int>(ceil(NumVec[6] / 2.0));

		int SetCount = 0;
		for (size_t i = 0; i < NumVec.size() - 1; i++)
		{
			if (SetCount < NumVec[i])
			{
				SetCount = NumVec[i];
			}
		}

		std::cout << SetCount;
	}

	void BOJ_vector::Problem_2577()
	{
		int A = 0, B = 0, C = 0;
		std::cin >> A >> B >> C;

		int Mul = A * B * C;
		std::vector<int> NumVec(10, 0);
		while (0 != Mul)
		{
			++NumVec[Mul % 10];
			Mul /= 10;
		}

		for (size_t i = 0; i < NumVec.size(); i++)
		{
			std::cout << NumVec[i] << std::endl;
		}
	}

	void BOJ_vector::Problem_3273()
	{
		int n = 0;
		std::cin >> n;

		std::vector<int> Sequence;
		Sequence.reserve(n);

		for (size_t i = 0; i < Sequence.capacity(); i++)
		{
			int Num = 0;
			std::cin >> Num;
			Sequence.push_back(Num);
		}

		sort(Sequence.begin(), Sequence.end());

		int x = 0;
		std::cin >> x;

		int Count = 0;
		int Left = 0, Right = static_cast<int>(Sequence.size() - 1);
		while (Left < Right)
		{
			if (x < Sequence[Left] + Sequence[Right])
			{
				--Right;
			}
			else if (x > Sequence[Left] + Sequence[Right])
			{
				++Left;
			}
			else
			{
				++Left; --Right; ++Count;
			}
		}

		std::cout << Count;
	}

	void BOJ_vector::Problem_10808()
	{
		std::string Word = "";
		std::cin >> Word;

		std::vector<int> Alphabet(26, 0);
		for (size_t i = 0; i < Word.size(); i++)
		{
			++Alphabet[Word[i] - 'a'];
		}

		for (size_t i = 0; i < Alphabet.size(); i++)
		{
			std::cout << Alphabet[i] << " ";
		}
	}

}
