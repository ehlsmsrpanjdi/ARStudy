#pragma once
class JWBJVector
{
public:
	JWBJVector();
	~JWBJVector();

	JWBJVector(const JWBJVector& _Other) = delete;
	JWBJVector(JWBJVector&& _Other) noexcept = delete;
	JWBJVector& operator=(const JWBJVector& _Other) = delete;
	JWBJVector& operator=(JWBJVector&& _Other) noexcept = delete;

	void BJ10808()
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
	void BJ2577()
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
	void BJ1475()
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
	void BJ3273()
	{
		// 시간 초과
		int n = 0;
		std::cin >> n;
		std::vector<int> Numbers;
		Numbers.resize(n);
		int Insert = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> Insert;
			Numbers[i] = Insert;
		}
		int CheckNum = 0;
		std::cin >> CheckNum;

		int Result = 0;
		int Check = 0;
		for (int i = 0; i < Numbers.size() - 1; i++)
		{
			for (int j = i + 1; j < Numbers.size(); j++)
			{
				Check = 0;
				Check = Numbers[i] + Numbers[j];
				if (Check == CheckNum)
				{
					++Result;
				}
			}
		}
		std::cout << Result;
	}
	void BJ10807()
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
	void BJ13300()
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
	void BJ11328()
	{

	}
	void BJ1919()
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

protected:

private:

};

