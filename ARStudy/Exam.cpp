#include "PreCompile.h"
#include <assignment/SMQueue.h>

int main() 
{
	LeakCheck;
	
	{
		TimeTest("JWList");

		JWList<int> List;
		for (int i = 0; i < 10000000; ++i)
		{
			List.push_back(i);
		}
	}
	
	{
		TimeTest("std::list");

		std::list<int> List;
		for (int i = 0; i < 10000000; ++i)
		{
			List.push_back(i);
		}
	}

	{
		TimeTest("SMQueue");

		SMQueue<int> Q;
		Q.Push(3);
	}
}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/