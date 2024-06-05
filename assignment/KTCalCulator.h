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
	// 직접 구현하는게 아니라 함수 내부에서 구현해라 
