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

	void BOJ_vector::Problem_1919()
	{
		std::string str1 = "", str2 = "";
		std::cin >> str1 >> str2;

		std::vector<int> Alpha(26, 0);
		for (size_t i = 0; i < str1.size(); i++)
		{
			++Alpha[str1[i] - 'a'];
		}

		for (size_t i = 0; i < str2.size(); i++)
		{
			--Alpha[str2[i] - 'a'];
		}

		int Count = 0;
		for (size_t i = 0; i < Alpha.size(); i++)
		{
			Count += abs(Alpha[i]);
		}

		std::cout << Count;
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
				++Left; 
				--Right; 
				++Count;
			}
		}

		std::cout << Count;
	}

	void BOJ_vector::Problem_10807()
	{
		int N = 0;
		std::cin >> N;

		int Num = 0;

		std::vector<int> NumVec;
		NumVec.reserve(N);
		for (int i = 0; i < NumVec.capacity(); i++)
		{
			std::cin >> Num;
			NumVec.push_back(Num);
		}

		int v = 0, count = 0;
		std::cin >> v;
		for (size_t i = 0; i < NumVec.size(); i++)
		{
			if (v == NumVec[i])
			{
				++count;
			}
		}

		std::cout << count;
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

	void BOJ_vector::Problem_11328()
	{
		int N = 0;
		std::cin >> N;

		for (int i = 0; i < N; i++)
		{
			std::string str1 = "", str2 = "";
			std::cin >> str1 >> str2;

			sort(str1.begin(), str1.end());
			sort(str2.begin(), str2.end());

			if (str1 == str2)
			{
				std::cout << "Possible\n";
			}
			else
			{
				std::cout << "Impossible\n";
			}
		}
	}

	void BOJ_vector::Problem_13300()
	{
		int N = 0, K = 0;
		std::cin >> N >> K;

		std::vector<int> Girl(6, 0);
		std::vector<int> Boy(6, 0);

		int S = 0, Y = 0;
		for (int i = 0; i < N; i++)
		{
			std::cin >> S >> Y;

			switch (S)
			{
			case 0:
				++Girl[Y - 1];
				break;
			case 1:
				++Boy[Y - 1];
				break;
			}
		}

		int Count = 0;
		for (size_t i = 0; i < 6; i++)
		{
			float fK = static_cast<float>(K);
			Count += static_cast<int>(ceil(Girl[i] / fK));
			Count += static_cast<int>(ceil(Boy[i] / fK));
		}

		std::cout << Count;
	}
}
