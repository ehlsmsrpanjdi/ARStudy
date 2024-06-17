#include "PreCompile.h"
#include "JYBJVector.h"

JYBJVector::JYBJVector()
{

}

JYBJVector::~JYBJVector()
{

}

int JYBJVector::BJ10808()
{
	std::string S;
	int SCnt;
	std::vector<int> Alphabet(26, 0);
	int Index;

	std::cin >> S;
	SCnt = size(S);

	for (int i = 0; i < SCnt; i++)
	{
		Index = S[i] - 97;
		Alphabet[Index] += 1;
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << Alphabet[i] << " ";
	}

	return 0;
}

int JYBJVector::BJ2577()
{
	int A, B, C, Res;
	std::vector<int> Number(10, 0);
	int Index;

	std::cin >> A >> B >> C;
	Res = A * B * C;

	while (Res > 0)
	{
		Index = Res % 10;
		Number[Index] += 1;

		Res /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << Number[i] << "\n";
	}

	return 0;
}

int JYBJVector::BJ1475()
{
	int N, Index;
	std::vector<int> Cnt(10, 0);
	int Min = 0;

	std::cin >> N;

	while (N > 0)
	{
		Index = N % 10;
		Cnt[Index] += 1;

		N /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 6)
		{
			int Cnt69 = Cnt[6] + Cnt[9];

			if (Cnt69 > Min * 2)
			{
				if (Cnt69 % 2 == 0)
				{
					Min = Cnt69 / 2;
				}
				else
				{
					Min = Cnt69 / 2 + 1;
				}
			}
		}
		else if (i == 9)
		{

		}
		else
		{
			if (Cnt[i] > Min)
			{
				Min = Cnt[i];
			}
		}
	}

	std::cout << Min;

	return 0;
}

int JYBJVector::BJ3273()
{

}

int JYBJVector::BJ10807()
{
	int N, Num, v;
	std::vector<int> NumVector;
	int Cnt = 0;

	std::cin >> N;
	NumVector.reserve(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Num;
		NumVector[i] = Num;
	}

	std::cin >> v;

	for (int i = 0; i < N; i++)
	{
		if (NumVector[i] == v)
		{
			Cnt += 1;
		}
	}

	std::cout << Cnt;

	return 0;
}

int JYBJVector::BJ13300()
{

}

int JYBJVector::BJ11328()
{

}

int JYBJVector::BJ1919()
{

}