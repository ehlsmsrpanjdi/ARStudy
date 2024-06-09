#include "PreCompile.h"
#include "assignment/JWQueue.h"
#include "assignment/YDUser.h"
#include <assignment/SJRamyeon.h>

int main()
{
	LeakCheck;

	{
		lsj::Store Store(4, 100000);
		std::cout << "요리 전:" << Store.GetCookedCount() << std::endl;
		Store.Cook();
		std::cout << "요리 후:" << Store.GetCookedCount() << std::endl;
	}

	SMRM RM;
	RM.Count(4, 1000000);
	RM.Start();

	{
		std::cout << "경윤 라면가게 오픈" << std::endl;

		{
			KYRamyeon KYRMStore;
			KYRMStore.OrderSetting(4, 100000);
			TimeTest("KYRMThread");
			KYRMStore.CookingStart();
		}

		{
			KYRamyeon KYRMStore;
			KYRMStore.OrderSetting(4, 100000);
			TimeTest("KYRMOrigin");
			KYRMStore.OriginCookingStart();
		}

		std::cout << "준비된 체력이 소진되어 마감합니다..." << std::endl;
	}
}

/*
ARStudy 항상 있던 포폴에서 App의 역활 여기서 우리가 만든거 시간 측정할꺼

EngineTool 시간 계산, 간단한 라이브러리 등등 여기 다 집어넣을거임

Task 만들 곳 오늘은 List이니 List폴더에 자기 이름 폴더 하나 만들어서 거기에 구현하기





*/