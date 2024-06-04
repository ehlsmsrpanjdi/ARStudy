#pragma once
#include <functional>
#include <map>


// 펑셔널, 람다로만 계산기 구현

// 설명 :
class KYCalculator
{
public:
	// constrcuter destructer
	KYCalculator();
	KYCalculator(std::string_view _CalString);

	~KYCalculator();

	// delete Function
	KYCalculator(const KYCalculator& _Other) = delete;
	KYCalculator(KYCalculator&& _Other) noexcept = delete;
	KYCalculator& operator=(const KYCalculator& _Other) = delete;
	KYCalculator& operator=(KYCalculator&& _Other) noexcept = delete;


protected:

private:
	std::string CalString = "";
	std::map<char, std::function<int(int, int)>> Operator = std::map<char, std::function<int(int, int)>>();
	
	std::vector<int> CalNum = std::vector<int>();
	std::vector<char> CalOperator = std::vector<char>();
};

