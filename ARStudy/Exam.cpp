#include "PreCompile.h"
#include <assignment/USMList.h>
int main() 
{
	LeakCheck;
	USMList<int> a;
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	a.PushBack(4);



	a.Remove(3);
	int c = 0;
}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/