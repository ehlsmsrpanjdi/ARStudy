#pragma once
#include "PreCompile.h"

namespace lsj
{
	template<typename T>
	class queue
	{
	public:
		queue() {}
		~queue() {}

		queue(const queue& _Other) = delete;
		queue(queue&& _Other) noexcept = delete;
		queue& operator=(const queue& _Other) = delete;
		queue& operator=(queue&& _Other) noexcept = delete;

		void push(const T& _Value)
		{
			List.push_back(_Value);
		}

		void pop()
		{
			List.pop_front();
		}

		T& front()
		{
			return List.front();
		}

		T& back()
		{
			return List.back();
		}

		bool empty()
		{
			return List.empty();
		}

		int size()
		{
			return List.size();
		}

	protected:


	private:
		std::list<T> List;

	};

}
