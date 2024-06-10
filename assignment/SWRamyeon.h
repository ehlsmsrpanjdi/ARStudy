#pragma once

namespace ksw
{
	enum class ECookType
	{
		Mutex,
		Atomic
	};

	class RamyeonStore
	{
	public:
		// constructor destructor
		RamyeonStore(size_t _StoveCount, size_t _RamyeonCount);
		~RamyeonStore();

		// delete Function
		RamyeonStore(const RamyeonStore& _Other) = delete;
		RamyeonStore(RamyeonStore&& _Other) noexcept = delete;
		RamyeonStore& operator=(const RamyeonStore& _Other) = delete;
		RamyeonStore& operator=(RamyeonStore&& _Other) noexcept = delete;

	public:
		void Cooking(ECookType _CookType);
	
	private:
		void BeforeInfo();
		void AfterInfo(ECookType _CookType);

	
	private:
		size_t StoveCount = 0;
		size_t RamyeonCount = 0;
		size_t SellRamyeonCount = 0;
		std::atomic<size_t> AtomicSellRamyeonCount = 0;

		std::vector<std::thread*> Stove;
	};
}