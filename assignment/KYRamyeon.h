#pragma once

// Ό³Έν :
class KYRamyeon
{
public:
	// constrcuter destructer
	KYRamyeon();
	~KYRamyeon();

	//// delete Function
	//KYRamyeon(const KYRamyeon& _Other) = delete;
	//KYRamyeon(KYRamyeon&& _Other) noexcept = delete;
	//KYRamyeon& operator=(const KYRamyeon& _Other) = delete;
	//KYRamyeon& operator=(KYRamyeon&& _Other) noexcept = delete;

	void CookingStart();
	void OrderSetting(int _GasRangeNum, int _RamenNum);

protected:

private:
	int GasRangeNum = -1;
	int RamenNum = -1;
};

