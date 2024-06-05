#include "PreCompile.h"
#include "SMCal.h"

void SMUser::Select(int _Left, char _Which, int _Right)
{
	SMCal Cal;
		switch (_Which)
		{
		case '+':
		{
			Cal.Fun = [=, &Cal](int, int)->int {
				Cal.Result = (_Left + _Right);
				return Cal.Result;
				};
			std::cout << Cal.Fun(_Left, _Right);
		}
		break;
		case '-':
		{
			Cal.Fun = [=, &Cal](int, int)->int {
				Cal.Result = (_Left - _Right);
				return Cal.Result;
				};
			std::cout << Cal.Fun(_Left, _Right);
		}
		break;
		default:
			break;
		}
}
