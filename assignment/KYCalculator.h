#pragma once

// Ό³Έν :
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

