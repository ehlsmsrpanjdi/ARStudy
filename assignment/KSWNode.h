#pragma once

namespace ksw
{
	// ���� : Node Ŭ����
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
