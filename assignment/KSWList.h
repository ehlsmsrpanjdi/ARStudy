#pragma once

namespace ksw
{
	// 설명 : list 클래스
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

	public:
		void push_back(int _Value);

	private:


	};
}

