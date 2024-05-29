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
		while (FrontNode != nullptr)
		{
			Node* TempNode = FrontNode;
			FrontNode = FrontNode->Next;
			delete TempNode;
		}
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

	void push(DataType _Value)
	{
		Node* NewNode = new Node();
		NewNode->Prev = BackNode->Prev;
		NewNode->Next = BackNode;
		NewNode->Value = _Value;

		BackNode->Prev->Next = NewNode;
		BackNode->Prev = NewNode;
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
};