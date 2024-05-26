#pragma once

namespace ksw
{
	// Ό³Έν : list
	class list
	{
	public:
		// constructor destructor
		list();
		~list();

		// delete Function
		list(const list& _Other) = delete;
		list(list&& _Other) noexcept = delete;
		list& operator=(const list& _Other) = delete;
		list& operator=(list&& _Other) noexcept = delete;

	protected:

	private:


	};
}

