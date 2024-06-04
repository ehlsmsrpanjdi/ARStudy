#pragma once

// 펑셔널, 람다로만 계산기 구현

// 설명 :
class KYCalculator
{
public:
	// constrcuter destructer
	KYCalculator();
	~KYCalculator();

	// delete Function
	KYCalculator(const KYCalculator& _Other) = delete;
	KYCalculator(KYCalculator&& _Other) noexcept = delete;
	KYCalculator& operator=(const KYCalculator& _Other) = delete;
	KYCalculator& operator=(KYCalculator&& _Other) noexcept = delete;



protected:

private:


};

