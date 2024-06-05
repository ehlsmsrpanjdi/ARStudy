#include "PreCompile.h"
#include "SMCal.h"

void SMUser::Select(int _Left, char _Which, int _Right)
{
		switch (_Which)
		{
		case '+':
		{
			Cal.Fun = [=](int, int)->int {
				Cal.Result = _Left + _Right;
				return Cal.Result;
				};
			std::cout << Cal.Fun(_Left, _Right);
		}
		break;
		case '-':
		{
			Cal.Fun = [=](int, int)->int {
				Cal.Result = _Left - _Right;
				return Cal.Result;
				};
			std::cout << Cal.Fun(_Left, _Right);
		}
		break;
		default:
			break;
		}
}
