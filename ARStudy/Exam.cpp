#include "PreCompile.h"
#include "assignment/JWQueue.h"
#include "assignment/YDUser.h"
int main()
{
	LeakCheck;

	SMUser User;
	User.Select(3, '+', 3);
	int a = 0;

	YDUser<int> Y;
	int res = Y.InputExpression(3, '+', 7);
}

/*
ARStudy �׻� �ִ� �������� App�� ��Ȱ ���⼭ �츮�� ����� �ð� �����Ҳ�

EngineTool �ð� ���, ������ ���̺귯�� ��� ���� �� �����������

Task ���� �� ������ List�̴� List������ �ڱ� �̸� ���� �ϳ� ���� �ű⿡ �����ϱ�





*/