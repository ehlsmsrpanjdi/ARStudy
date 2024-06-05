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
		void Start();

	private:
		void Init();

	private:
		std::map<int, std::function<void(float)>> Operator;
		std::function<int(char)> GetPriority;
		std::stack<std::string> Memory;
		float Temp = 0.0f;

	private:
		enum class ESymbol
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