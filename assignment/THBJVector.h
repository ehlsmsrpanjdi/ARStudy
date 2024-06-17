#pragma once

namespace lth
{
	class THBJVector
	{
	public:
		// constrcuter destructer
		THBJVector();
		~THBJVector();

		// delete Function
		THBJVector(const THBJVector& _Other) = delete;
		THBJVector(THBJVector&& _Other) noexcept = delete;
		THBJVector& operator=(const THBJVector& _Other) = delete;
		THBJVector& operator=(THBJVector&& _Other) noexcept = delete;

		static void BJ_10808();
		static void BJ_2577();
		static void BJ_1475();
		static void BJ_3273();
		static void BJ_10807();
		static void BJ_13300();
		static void BJ_11328();
		static void BJ_1919();

	protected:

	private:

	};
}

