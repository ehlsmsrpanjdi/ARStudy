#pragma once
#include <map>
#include <functional>

class JWCalculator
{
public:
	JWCalculator();
	~JWCalculator();

	JWCalculator(const JWCalculator& _Other) = delete;
	JWCalculator(JWCalculator&& _Other) noexcept = delete;
	JWCalculator& operator=(const JWCalculator& _Other) = delete;
	JWCalculator& operator=(JWCalculator&& _Other) noexcept = delete;
	
	void Start();
	inline void SetFirst(float _Number)
	{
		ResultTemp = _Number;
	}
	std::map<char, std::function<float(float)>> Order;

protected:

private:
	float ResultTemp = 0;
};

