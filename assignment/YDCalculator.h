#pragma once
#include <functional>

template<typename Type>
class YDCalculator
{
public:
	YDCalculator()
	{
	}

	~YDCalculator()
	{
	}


	YDCalculator(const YDCalculator& _Other) = delete;
	YDCalculator(YDCalculator&& _Other) noexcept = delete;
	YDCalculator& operator=(const YDCalculator& _Other) = delete;
	YDCalculator& operator=(YDCalculator&& _Other) noexcept = delete;

	std::function<Type(Type, Type)> MyFunc;
protected:

private:

};

