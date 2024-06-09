#pragma once

namespace ksw
{
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
		void BeforeInfo();
		void AfterInfo();

		void Cooking();
	
	private:
		size_t StoveCount = 0;
		size_t RamyeonCount = 0;
		size_t SellRamyeonCount = 0;

		std::vector<std::thread*> Stove;
	};
}