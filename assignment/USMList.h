#pragma once

// Ό³Έν :
class USMList
{
public:
	// constrcuter destructer
	USMList();
	~USMList();

	// delete Function
	USMList(const USMList& _Other) = delete;
	USMList(USMList&& _Other) noexcept = delete;
	USMList& operator=(const USMList& _Other) = delete;
	USMList& operator=(USMList&& _Other) noexcept = delete;

protected:

private:

};

