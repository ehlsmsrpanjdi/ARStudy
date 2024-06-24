#pragma once

namespace ksw
{
	class BOJ_Search
	{
	public:
		// constructor destructor
		BOJ_Search();
		~BOJ_Search();

		// delete Function
		BOJ_Search(const BOJ_Search& _Other) = delete;
		BOJ_Search(BOJ_Search&& _Other) noexcept = delete;
		BOJ_Search& operator=(const BOJ_Search& _Other) = delete;
		BOJ_Search& operator=(BOJ_Search&& _Other) noexcept = delete;

	public:
		static void Problem_1926();
		static void Problem_2178();

	};

}