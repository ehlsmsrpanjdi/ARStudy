#pragma once

template<typename DataType>
class JYQueue
{
private:
	class Node
	{
	public:
		Node() {}
		Node(DataType _Value)
			: Value(_Value)
		{

		}
		~Node() {}

		Node* Prev = nullptr;
		Node* Next = nullptr;
		DataType Value;
	};

public:
	JYQueue()
	{
		Head = new Node();
		Tail = new Node();

		Head->Next = Tail;
		Tail->Prev = Head;
	}

	~JYQueue()
	{
		Node* IterNode = Head;

		while (IterNode != nullptr)
		{
			Node* CurNode = IterNode;
			IterNode = IterNode->Next;

			delete CurNode;
			CurNode = nullptr;
		}
	}

	DataType& front()
	{
		if (empty() == true)
		{
			MsgBoxAssert("queue가 비어 있습니다.")
		}

		Node* Front = Head->Next;
		return Front->Value;
	}

	DataType& back()
	{
		if (empty() == true)
		{
			MsgBoxAssert("queue가 비어 있습니다.")
		}

		Node* Back = Tail->Prev;
		return Back->Value;
	}

	void push(const DataType& _Value)
	{
		Node* NewNode = new Node(_Value);
		
		if (empty() == true)
		{
			Head->Next = NewNode;
			NewNode->Prev = Head;
		}
		else
		{
			Tail->Prev->Next = NewNode;
			NewNode->Prev = Tail->Prev;
		}

		NewNode->Next = Tail;
		Tail->Prev = NewNode;

		Size += 1;
		return;
	}

	void pop()
	{
		if (empty() == true)
		{
			MsgBoxAssert("pop할 노드가 없습니다.")
			return;
		}

		Node* Front = Head->Next;
		
		Head->Next = Front->Next;
		Front->Next->Prev = Head;

		delete Front;
		Front = nullptr;

		Size -= 1;
		return;
	}

	bool empty()
	{
		if (Head->Next == Tail)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	size_t size()
	{
		return Size;
	}

private:
	Node* Head = nullptr;
	Node* Tail = nullptr;
	size_t Size = 0;
};