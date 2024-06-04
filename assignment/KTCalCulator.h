#pragma once
class KTCalCulator
{
public:

	KTCalCulator();
	~KTCalCulator();

	KTCalCulator(const KTCalCulator& _Other) = delete;
	KTCalCulator(KTCalCulator&& _Other) noexcept = delete;
	KTCalCulator& operator=(const KTCalCulator& _Other) = delete;
	KTCalCulator& operator=(KTCalCulator&& _Other) noexcept = delete;

	void Start();
	void SetOperator();
private	:

	char Operator;
	float Num1 = 0;
	float Num2 = 0;
	float Result = 0;
};

