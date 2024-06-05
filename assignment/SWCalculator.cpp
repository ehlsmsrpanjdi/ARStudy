#include "PreCompile.h"
#include "SWCalculator.h"

namespace ksw
{
	calculator::calculator()
	{
		Calculation[ESymbol::PLUS]	= [=](float _Num) { Temp += _Num; };
		Calculation[ESymbol::MINUS] = [=](float _Num) { Temp -= _Num; };
		Calculation[ESymbol::MUL]	= [=](float _Num) { Temp *= _Num; };
		Calculation[ESymbol::DIV]	= [=](float _Num) { Temp /= _Num; };

		GetPriority = [](char _Input)->int
			{
				ESymbol Input = static_cast<ESymbol>(_Input);

				switch (Input)
				{
				case ESymbol::L_PARENTHESIS:
					return 0;
				case ESymbol::PLUS:
				case ESymbol::MINUS:
					return 1;
				case ESymbol::MUL:
				case ESymbol::DIV:
					return 2;
				case ESymbol::SPACE:
					return 3;
				default:
					MsgBoxAssert("�߸��� �Է��Դϴ�.");
					return -1;
				}
			};

		ConvertToPostFix = [&](std::string_view _Input)
			{
				std::string Input = _Input.data();
				std::string Temp;

				int Idx = 0;
				while (Idx < Input.size())
				{
					char Text = Input[Idx];

					// �ǿ����� �϶�
					if (true == IsNum(Text))
					{
						Temp += Text;
						++Idx;
						if (false == IsNum(Input[Idx]))
						{
							PostFix.push(Temp);
							Temp = "";
						}
					}
					// ������ �϶�
					else if (true == IsToken(Text))
					{
						if (true == Token.empty())
						{
							if (ESymbol::R_PARENTHESIS == Text)
							{
								MsgBoxAssert("�߸��� �Է��Դϴ�.");
								return;
							}

							Token.push(Text);
						}
						else
						{
							if (ESymbol::R_PARENTHESIS == Text)
							{
								while (true)
								{
									char Top = Token.top();
									if (ESymbol::L_PARENTHESIS == Top)
									{
										Token.pop();
										break;
									}
									else
									{
										std::string str; 
										str = Top;
										PostFix.push(str);
										Token.pop();
									}
								}
							}
							// �켱 ���� ��
							else if (true == CompPriority(Token.top(), Text))
							{
								char Top = Token.top();
								Token.pop();
								Token.push(Text);
								Token.push(Top);
							}
							else
							{
								Token.push(Text);
							}
						}

						++Idx;
					}
					else
					{
						if (ESymbol::SPACE == Text)
						{
							++Idx;
						}
						else
						{
							MsgBoxAssert("�߸��� �Է��Դϴ�.");
							return;
						}
					}
				}

				while (true)
				{

				}

				
			};

		CompPriority = [&](char _Top, char _Cur)->bool 
			{
				int TopPriority = GetPriority(_Top);
				int CurPriority = GetPriority(_Cur);

				if (CurPriority < TopPriority)
				{
					return true;
				}
				else
				{
					return false;
				}
			};

		IsToken = [](char _Value)->bool
			{
				switch (_Value)
				{
				case ESymbol::L_PARENTHESIS:
				case ESymbol::R_PARENTHESIS:
				case ESymbol::MUL:
				case ESymbol::DIV:
				case ESymbol::PLUS:
				case ESymbol::MINUS:
					return true;
				default:
					return false;
				}
			};

		IsNum = [](char _Value)->bool 
			{
				if ('0' <= _Value && '9' >= _Value || '.' == _Value)
				{
					return true;
				}
				else
				{
					return false;
				}
			};

		Start = [&]
			{
				while (true)
				{
					std::string Input = "";
					std::getline(std::cin, Input);
					
					ConvertToPostFix(Input);


					// ���
					std::cout << Temp << std::endl;
				};
			};

		
		
		




	}

	calculator::~calculator()
	{
	}
}
