#include "PreCompile.h"
#include <assignment/USMList.h>
int main() 
{
	LeakCheck;
	
	EngineTime Timer;

	{
		Timer.Reset();

		JWList<int> List;
		for (int i = 0; i < 10000000; ++i)
		{
			List.push_back(i);
		}

		double Time = Timer.TimeCheck();

		std::cout << "JWList: " << Time << "��" << std::endl;
	}
	
	{
		Timer.Reset();

		std::list<int> List;
		for (int i = 0; i < 10000000; ++i)
		{
			List.push_back(i);
		}

		double Time = Timer.TimeCheck();

		std::cout << "std::list: " << Time << "��" << std::endl;
	}
}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/