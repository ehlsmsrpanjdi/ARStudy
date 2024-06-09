#pragma once
#include <thread>
#include <functional>

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

	void TestFunction();

protected:

private:
	//int GasRangeNum = -1;
	//int RamenNum = -1;
	int GasRangeNum = 4;
	int RamenNum = 100000;
	int CookingCount = 0;

	std::thread Function1;
	std::vector<std::function<void()>> CookingThread;
};

