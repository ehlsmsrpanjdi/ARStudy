#pragma once

namespace ksw
{
	class BOJ_vector
	{
	public:
		// constrcuter destructer
		BOJ_vector();
		~BOJ_vector();

		// delete Function
		BOJ_vector(const BOJ_vector& _Other) = delete;
		BOJ_vector(BOJ_vector&& _Other) noexcept = delete;
		BOJ_vector& operator=(const BOJ_vector& _Other) = delete;
		BOJ_vector& operator=(BOJ_vector&& _Other) noexcept = delete;

	public:
		static void Problem_1475();
		static void Problem_2577();
		static void Problem_3273();
		static void Problem_10808();

	};
}


