#pragma once

template<typename DataType>
class THQueue
{
private:
	class Node
	{
	public:
		Node* Prev = nullptr;
		Node* Next = nullptr;

		DataType Value;
	};

public:
	THQueue()
	{
		FrontNode = new Node();
		BackNode = new Node();

		FrontNode->Next = BackNode;
		BackNode->Prev = FrontNode;
	}

	~THQueue()
	{

	}

	void empty()
	{

	}

	void size()
	{

	}

	void front()
	{

	}

	void back()
	{

	}

	void push(int _Value)
	{
		Node* NewNode = new Node();
		NewNode->Prev = FrontNode;
		NewNode->Next = BackNode;
		NewNode->Value = _Value;
	}

	void emplace()
	{

	}

	void pop()
	{

	}

	void swap()
	{

	}

protected:

private:
	Node* FrontNode = nullptr;
	Node* BackNode = nullptr;
	DataType Value;
};