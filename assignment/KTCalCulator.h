#pragma once
#include <functional>
class KTCalCulator
{
public:

	KTCalCulator();
	~KTCalCulator();

	KTCalCulator(const KTCalCulator& _Other) = delete;
	KTCalCulator(KTCalCulator&& _Other) noexcept = delete;
	KTCalCulator& operator=(const KTCalCulator& _Other) = delete;
	KTCalCulator& operator=(KTCalCulator&& _Other) noexcept = delete;

	void Input();

private	:
	std::function<void(float,float,char)> Fun;
	
private:
	float Result;
};



	


	//if

		//switch()
	//Fun = [](){}
	// ���� �����ϴ°� �ƴ϶� �Լ� ���ο��� �����ض� 
