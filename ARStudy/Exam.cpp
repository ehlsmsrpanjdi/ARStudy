#include "PreCompile.h"
#include <assignment/USMList.h>
int main() 
{
	LeakCheck;

	USMList<int> List;
	List.PushBack(3);
	List.PushBack(3);
	List.PushBack(3);
	List.PushBack(3);
	List.PushBack(3);
	List.PushBack(3);
	int a =  List.Size();

}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/