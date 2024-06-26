#pragma once

namespace ksw
{
	class calculator
	{
	public:
		// constrcuter destructer
		calculator();
		~calculator();

		// delete Function
		calculator(const calculator& _Other) = delete;
		calculator(calculator&& _Other) noexcept = delete;
		calculator& operator=(const calculator& _Other) = delete;
		calculator& operator=(calculator&& _Other) noexcept = delete;

	public:
		std::function<void()> Start;

	private:
		std::map<int, std::function<void(float, float)>> Operater;
		std::function<int(char)> GetPriority;
		std::function<bool(char, char)> CompPriority;
		std::function<bool(char)> IsToken;
		std::function<bool(char)> IsNum;
		std::function<void(std::string_view)> ConvertToPostFix;
		std::function<void()> CalCulation;

	private:
		std::queue<std::string> PostFix;
		std::stack<std::string> Result;
		std::stack<char> Token;
		float TempResult = 0.0f;

	private:
		enum ESymbol
		{
			L_PARENTHESIS = '(',
			R_PARENTHESIS = ')',
			MUL = '*',
			DIV = '/',
			PLUS = '+',
			MINUS = '-',
			SPACE = ' '
		};
	};
}