#include "PreCompile.h"
#include "assignment/JWQueue.h"

int main()
{
	LeakCheck;

	// Queue
#if 0
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

	{
		TimeTest("SMQueue");

		SMQueue<int> ydQ;
		for (int i = 0; i < 10000000; ++i)
		{
			ydQ.Push(i);
		}
		for (int i = 0; i < 10000000; ++i)
		{
			ydQ.Pop();
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

	{
		TimeTest("JWQueue");
		cjw::queue<int> thQ;
		for (int i = 0; i < 10000000; ++i)
		{
			thQ.push(i);
		}
		for (int i = 0; i < 10000000; ++i)
		{
			thQ.pop();
		}
	}

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


	{
		TimeTest("SWQueue");
		ksw::queue<int> Q;
		for (int i = 0; i < 10000000; ++i)
		{	
			Q.push(i);
		}
		for (int i = 0; i < 10000000; ++i)
		{
			Q.pop();
		}
	}
#endif

	// Calculator
	
	//JWCalculator
	{
		JWUser Test;
		Test.CalStart();
	}

	// KYCalculator
	{
		KYUser KYU;
		KYU.CalculateBegin();
	}
}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/