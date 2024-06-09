#include "PreCompile.h"
#include "assignment/JWQueue.h"
#include "assignment/YDUser.h"
#include <assignment/SJRamyeon.h>

int main()
{
	LeakCheck;

	{
		lsj::Store Store(4, 100000);
		std::cout << "�丮 ��:" << Store.GetCookedCount() << std::endl;
		Store.Cook();
		std::cout << "�丮 ��:" << Store.GetCookedCount() << std::endl;
	}

	SMRM RM;
	RM.Count(4, 1000000);
	RM.Start();

	{
		std::cout << "���� ��鰡�� ����" << std::endl;

		{
			TimeTest("KYRMThread");
			KYRamyeon KYRMStore;
			KYRMStore.OrderSetting(4, 100000);
			KYRMStore.CookingStart();
		}

		{
			TimeTest("KYRMOrigin");
			KYRamyeon KYRMStore;
			KYRMStore.OrderSetting(4, 100000);
			KYRMStore.OriginCookingStart();
		}

		std::cout << "�غ�� ü���� �����Ǿ� �����մϴ�..." << std::endl;
	}
}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/