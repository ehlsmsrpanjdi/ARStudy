#pragma once
#include <thread>
#include <functional>
#include <atomic>


// ���� :
class KYRamyeon
{
public:
	// constrcuter destructer
	KYRamyeon();
	~KYRamyeon();

	void CookingStart();
	void OriginCookingStart();
	void OrderSetting(int _GasRangeNum, int _RamenNum, bool _IsThreadOn = true);
	
protected:

private:
	bool IsThreadOn = true;
	int GasRangeNum = -1;
	int RamenNum = -1;
	std::atomic_int CookingCount = 0;

	std::vector<std::thread> CookingThread;
};

