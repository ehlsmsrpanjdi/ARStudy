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

		std::cout << "JWList: " << Time << "초" << std::endl;
	}
	
	{
		Timer.Reset();

		std::list<int> List;
		for (int i = 0; i < 10000000; ++i)
		{
			List.push_back(i);
		}

		double Time = Timer.TimeCheck();

		std::cout << "std::list: " << Time << "초" << std::endl;
	}
}

/*
ARStudy 항상 있던 포폴에서 App의 역활 여기서 우리가 만든거 시간 측정할꺼

EngineTool 시간 계산, 간단한 라이브러리 등등 여기 다 집어넣을거임

Task 만들 곳 오늘은 List이니 List폴더에 자기 이름 폴더 하나 만들어서 거기에 구현하기





*/