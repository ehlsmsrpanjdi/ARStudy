#pragma once

namespace ksw
{
	// 설명 : Node 클래스
	class Node
	{
	public:
		// constructor destructor
		Node();
		~Node();

		// delete Function
		Node(const Node& _Other) = delete;
		Node(Node&& _Other) noexcept = delete;
		Node& operator=(const Node& _Other) = delete;
		Node& operator=(Node&& _Other) noexcept = delete;



	protected:

	private:
		Node* Prev = nullptr;
		Node* Next = nullptr;

	};
}
