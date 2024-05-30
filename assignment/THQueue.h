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

	bool empty()
	{
		if (FrontNode->Next == BackNode)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	int size()
	{
		int count = 0;
		Node* TempNode = FrontNode->Next;
		while (TempNode != BackNode)
		{
			TempNode = TempNode->Next;
			count++;
		}
		return count;
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
		Node* TempNode = FrontNode->Next;
		if (TempNode != BackNode)
		{
			FrontNode->Next->Next->Prev = FrontNode;
			FrontNode->Next = FrontNode->Next->Next;
			delete TempNode;
		}
		else
		{
			return;
		}
	}

	void swap()
	{

	}

protected:

private:
	Node* FrontNode = nullptr;
	Node* BackNode = nullptr;
};