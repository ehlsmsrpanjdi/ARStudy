#pragma once

template<typename DataType>
class YDQueue
{
public:
	class Node
	{
	public:
		Node()
		{}
		~Node()
		{}

		Node(DataType _Data)
			:Data(_Data)
		{

		}

		DataType Data = DataType();
		Node* Prev = nullptr;
		Node* Next = nullptr;
	};

	YDQueue()
	{
		Start = new Node();
		End = new Node();

		Start->Next = End;
		End->Prev = Start;
	}
	~YDQueue()
	{
		while (Start != nullptr)
		{
			Node* dptr = Start;
			Start = Start->Next;
			delete dptr;
		}
	}

	void push(DataType _Data)
	{
		Node* NewNode = new Node(_Data);

		End->Prev->Next = NewNode;
		NewNode->Prev = End->Prev;
		End->Prev = NewNode;
		NewNode->Next = End;
	}

	void pop()
	{
		/*if (Start->Next == End)
		{
			MsgBoxAssert("비어있는 연두큐에 손을 대다니!! 다메요!!");
			return;
		}*/
		Node* Ptr = Start->Next;
		Start->Next = Ptr->Next;
		Ptr->Next->Prev = Start;
		delete Ptr;
	}

	DataType& front()
	{
		if (Start->Next == End)
		{
			MsgBoxAssert("연두 : 비어있는 큐에 front 값이 있겠냐??");
		}
		return Start->Next->Data;
	}

	DataType& back()
	{
		if (Start->Next == End)
		{
			MsgBoxAssert("연두 : 비어있는 큐에 back 값이 있겠냐??");
		}
		return End->Prev->Data;
	}

	bool empty()
	{
		return Start->Next == End;
	}

	size_t size()
	{
		size_t cnt = 0;
		Node* nextnode = Start->Next;
		while (nextnode != End)
		{
			nextnode = nextnode->Next;
			++cnt;
		}
		return cnt;
	}
protected:

private:
	Node* Start = nullptr;
	Node* End = nullptr;
};

