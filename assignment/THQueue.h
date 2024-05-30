#pragma once
#include <queue>

template<typename DataType>
class THQueue
{
private:
	class Node
	{
	public:
		Node* Prev = nullptr;
		Node* Next = nullptr;
		DataType Value = DataType();
	};

public:
	THQueue()
	{
		FrontDummyNode = new Node();
		BackDummyNode = new Node();

		FrontDummyNode->Next = BackDummyNode;
		BackDummyNode->Prev = FrontDummyNode;
	}

	~THQueue()
	{
		while (FrontDummyNode != nullptr)
		{
			Node* TempNode = FrontDummyNode;
			FrontDummyNode = FrontDummyNode->Next;
			delete TempNode;
		}
	}

	bool empty()
	{
		if (FrontDummyNode->Next == BackDummyNode)
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
		Node* TempNode = FrontDummyNode->Next;
		while (TempNode != BackDummyNode)
		{
			TempNode = TempNode->Next;
			count++;
		}
		return count;
	}

	DataType& front()
	{
		if (FrontDummyNode->Next == BackDummyNode)
		{
			MsgBoxAssert("FrontNode가 존재하지 않습니다.");
		}
		return FrontDummyNode->Next->Value;
	}

	DataType& back()
	{
		if (BackDummyNode->Prev == FrontDummyNode)
		{
			MsgBoxAssert("BackNode가 존재하지 않습니다.");
		}
		return BackDummyNode->Prev->Value;
	}

	void push(DataType _Value)
	{
		Node* NewNode = new Node();
		NewNode->Prev = BackDummyNode->Prev;
		NewNode->Next = BackDummyNode;
		NewNode->Value = _Value;

		BackDummyNode->Prev->Next = NewNode;
		BackDummyNode->Prev = NewNode;
	}

	void emplace()
	{

	}

	void pop()
	{
		Node* TempNode = FrontDummyNode->Next;
		if (TempNode != BackDummyNode)
		{
			FrontDummyNode->Next->Next->Prev = FrontDummyNode;
			FrontDummyNode->Next = FrontDummyNode->Next->Next;
			delete TempNode;
		}
		else
		{
			return;
		}
	}

	void swap(THQueue _Queue0, THQueue _Queue1)
	{

	}

protected:

private:
	Node* FrontDummyNode = nullptr;
	Node* BackDummyNode = nullptr;
};