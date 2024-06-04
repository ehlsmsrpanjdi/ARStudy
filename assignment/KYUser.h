#pragma once

// Ό³Έν :
class KYUser
{
public:
	// constrcuter destructer
	KYUser();
	~KYUser();

	// delete Function
	KYUser(const KYUser& _Other) = delete;
	KYUser(KYUser&& _Other) noexcept = delete;
	KYUser& operator=(const KYUser& _Other) = delete;
	KYUser& operator=(KYUser&& _Other) noexcept = delete;

	void CalculateBegin();

protected:

private:

};

