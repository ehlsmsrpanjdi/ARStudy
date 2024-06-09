#pragma once
class JWRamyeon
{
public:
	JWRamyeon();
	~JWRamyeon();

	JWRamyeon(const JWRamyeon& _Other) = delete;
	JWRamyeon(JWRamyeon&& _Other) noexcept = delete;
	JWRamyeon& operator=(const JWRamyeon& _Other) = delete;
	JWRamyeon& operator=(JWRamyeon&& _Other) noexcept = delete;

	void Open();

protected:
	void RamyeonOrder();
	void Result();

private:
	std::vector<std::thread*> RamyeonMachine;
	int Count = 0;
	int MachineCount = 4;
	int OrderCount = 100000;
	int MachinePerOrder = 0;
};

