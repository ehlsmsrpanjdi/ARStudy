#include "PreCompile.h"


int main() 
{
	LeakCheck;
	//{
	//	TimeTest("SMQueue");

	//	SMQueue<int> Q;
	//	Q.Push(3);
	//}

	{
		TimeTest("SJQueue");

		lsj::queue<int> Queue;
		for (int i = 0; i < 10000000; ++i)
		{
			Queue.push(i);
		}
		for (int i = 0; i < 10000000; ++i)
		{
			Queue.pop();
		}
	}

	// KYQueue
	{
		{
			KYQueue Q;

			Q.push(1);
			bool Value = Q.empty();
			
			std::cout << Value << std::endl;
		}

		
		{
			//std::queue<int> Q;
			//
			//Q.push()
			//bool Value = Q.empty();

			//std::cout << Value << std::endl;
		}
	}

	{
		TimeTest("YDQueue");

		YDQueue<int> ydQ;
		for (int i = 0; i < 10000000; ++i)
		{
			ydQ.push(i);
		}
		for (int i = 0; i < 10000000; ++i)
		{
			ydQ.pop();
		}
	}
}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/