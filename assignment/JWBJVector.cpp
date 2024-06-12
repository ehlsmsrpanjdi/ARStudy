#include "PreCompile.h"
#include "JWBJVector.h"

JWBJVector::JWBJVector()
{
}

JWBJVector::~JWBJVector()
{
}

void JWBJVector::BJ10808()
{
	// 완
	std::vector<int> Result;
	Result.resize(26);
	std::string S;
	std::cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		char Test = 'a';
		char Alphabet = S[i];
		int AlphaNum = static_cast<int>(Alphabet) - 97;
		++Result[AlphaNum];
	}

	for (int i = 0; i < Result.size(); i++)
	{
		std::cout << Result[i] << " ";
	}
}

void JWBJVector::BJ2577()
{
	// 완
	std::vector<int> Result;
	Result.resize(10);
	int Total = 1;
	int Input;
	for (int i = 0; i < 3; i++)
	{
		std::cin >> Input;
		Total *= Input;
	}

	std::string IntToString = std::to_string(Total);
	for (int i = 0; i < IntToString.size(); i++)
	{
		char TempChar = IntToString[i];
		int Index = static_cast<int>(TempChar) - '0';
		++Result[Index];
	}

	for (int i = 0; i < Result.size(); i++)
	{
		std::cout << Result[i] << std::endl;
	}
}

void JWBJVector::BJ1475()
{
	// 완
	std::vector<int> Count;
	Count.resize(10);
	int N = 0;
	std::cin >> N;
	std::string IntToString = std::to_string(N);

	for (int i = 0; i < IntToString.size(); i++)
	{
		int Index = static_cast<int>(IntToString[i]) - static_cast<int>('0');
		if (6 == Index || 9 == Index)
		{
			if (Count[6] >= Count[9])
			{
				++Count[9];
			}
			else
			{
				++Count[6];
			}
		}
		else
		{
			++Count[Index];
		}
	}

	int Max = *std::max_element(Count.begin(), Count.end());
	std::cout << Max;
}

void JWBJVector::BJ3273()
{
	// 완
	int n = 0;
	std::cin >> n;
	std::vector<int> All;
	All.resize(2000001);
	std::vector<int> Numbers;
	Numbers.resize(n);
	int Insert = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> Insert;
		Numbers[i] = Insert;
		All[Insert] = 1;
	}
	int CheckNum = 0;
	std::cin >> CheckNum;

	int Count = 0;
	for (int i = 0; i < Numbers.size(); i++)
	{
		int Index = CheckNum - Numbers[i];
		if (Index >= 0)
		{
			if (1 == All[Index])
			{
				if (Numbers[i] < Index)
				{
					Count++;
				}
			}
		}
	}
	std::cout << Count;
}

void JWBJVector::BJ10807()
{
	// 완
	int N = 0;
	std::cin >> N;
	std::vector<int> Numbers(N);
	int Insert = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> Insert;
		Numbers[i] = Insert;
	}

	int v = 0;
	std::cin >> v;

	int Count = 0;
	for (int i = 0; i < Numbers.size(); i++)
	{
		if (v == Numbers[i])
		{
			++Count;
		}
	}
	std::cout << Count;
}

void JWBJVector::BJ13300()
{
	// 완
	std::vector<int> Man;
	std::vector<int> WoMan;
	Man.resize(6);
	WoMan.resize(6);
	int Result = 0;
	int N, K, S, Y;
	std::cin >> N;
	std::cin >> K;

	for (int i = 0; i < N; i++)
	{
		std::cin >> S;
		std::cin >> Y;
		Y = Y - 1;
		if (0 == S)
		{
			WoMan[Y]++;
		}
		else
		{
			Man[Y]++;
		}
	}

	for (int i = 0; i < Man.size(); i++)
	{
		Result += Man[i] / K;
		if (0 != Man[i] % K)
		{
			Result++;
		}
	}
	for (int i = 0; i < WoMan.size(); i++)
	{
		Result += WoMan[i] / K;
		if (0 != WoMan[i] % K)
		{
			Result++;
		}
	}
	std::cout << Result;
}

void JWBJVector::BJ11328()
{
	// 완
	int N;
	std::cin >> N;
	std::string Left;
	std::string Right;

	for (int i = 0; i < N; i++)
	{
		std::cin >> Left;
		std::cin >> Right;

		if (Left.size() != Right.size())
		{
			std::cout << "Impossible" << std::endl;
			continue;
		}

		std::sort(Left.begin(), Left.end());
		std::sort(Right.begin(), Right.end());

		if (false == (Left == Right))
		{
			std::cout << "Impossible" << std::endl;
			continue;
		}

		std::cout << "Possible" << std::endl;
	}
}

void JWBJVector::BJ1919()
{
	// 완
	std::vector<char> First;
	std::vector<char> Second;

	std::string Insert;

	std::cin >> Insert;
	First.resize(Insert.size());
	for (int i = 0; i < Insert.size(); i++)
	{
		First[i] = Insert[i];
	}

	std::cin >> Insert;
	Second.resize(Insert.size());
	for (int i = 0; i < Insert.size(); i++)
	{
		Second[i] = Insert[i];
	}

	int Result = 0;
	std::vector<char> Temp = Second;
	for (int i = 0; i < First.size(); i++)
	{
		char Alphabet = First[i];
		for (std::vector<char>::iterator iter = Temp.begin(); iter != Temp.end(); ++iter)
		{
			if (Alphabet == *iter)
			{
				Temp.erase(iter);
				Result++;
				break;
			}
		}
	}
	std::cout << First.size() - Result + Second.size() - Result;
}

void JWBJVector::BJ3273TwoPointer()
{
}
