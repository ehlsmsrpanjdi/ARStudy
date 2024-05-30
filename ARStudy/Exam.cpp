#include "PreCompile.h"


int main() 
{
	LeakCheck;
	//{
	//	TimeTest("SMQueue");

	//	SMQueue<int> Q;
	//	Q.Push(3);
	//}
	
	// SJQueue
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
		TimeTest("KYQueue");

		KYQueue<int> KYQ;
		for (int i = 0; i < 10000000; ++i)
		{
			KYQ.push(i);
		}
		for (int i = 0; i < 10000000; ++i)
		{
			KYQ.pop();
		}
	}

	// YDQueue
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

	// THQueue
	{
		TimeTest("THQueue");
		THQueue<int> thQ;
		for (int i = 0; i < 10000000; ++i)
		{
			thQ.push(i);
		}
		for (int i = 0; i < 10000000; ++i)
		{
			thQ.pop();
		}
	}

	// JYQueue
	{
		TimeTest("JYQueue");
		JYQueue<int> JYQ;
		for (int i = 0; i < 10000000; ++i)
		{
			JYQ.push(i);
		}
		for (int i = 0; i < 10000000; ++i)
		{
			JYQ.pop();
		}
	}
}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/