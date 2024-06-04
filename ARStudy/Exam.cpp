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
ARStudy 항상 있던 포폴에서 App의 역활 여기서 우리가 만든거 시간 측정할꺼

EngineTool 시간 계산, 간단한 라이브러리 등등 여기 다 집어넣을거임

Task 만들 곳 오늘은 List이니 List폴더에 자기 이름 폴더 하나 만들어서 거기에 구현하기





*/