#pragma once
#include <list>

template<typename DataType>
class JWList
{
private:
	struct Node
	{
		Node* Prev = nullptr;
		Node* Next = nullptr;
		DataType Data;
	};

public:
	class iterator
	{
		friend JWList;
	public:
		iterator()
		{
		}
		iterator(Node* _Node)
		{
			CurNode = _Node;
		}

		bool operator!=(const iterator& _iter)
		{
			bool Result = CurNode != _iter.CurNode;
			return Result;
		}

		void operator++()
		{
			CurNode = CurNode->Next;
		}

		DataType operator*()
		{
			return CurNode->Data;
		}


	protected:

	private:
		Node* CurNode = nullptr;
	};

public:
	JWList()
	{
		First = new Node();
		End = new Node();

		First->Next = End;
		End->Prev = First;
	}
	~JWList()
	{
		Node* Cur = First;
		while (nullptr != Cur)
		{
			Node* Temp = Cur->Next;

			delete Cur;
			Cur = Temp;
		}
	}

	JWList(const JWList& _Other) = delete;
	JWList(JWList&& _Other) noexcept = delete;
	JWList& operator=(const JWList& _Other) = delete;
	JWList& operator=(JWList&& _Other) noexcept = delete;

	void push_back(const DataType& _Data)
	{
		Node* InsertNode = new Node();
		InsertNode->Data = _Data;

		InsertNode->Next = End;
		InsertNode->Prev = End->Prev;

		End->Prev->Next = InsertNode;
		End->Prev = InsertNode;
	}

	void push_front(const DataType& _Data)
	{
		Node* InsertNode = new Node();
		InsertNode->Data = _Data;

		InsertNode->Prev = First;
		InsertNode->Next = First->Next;

		First->Next->Prev = InsertNode;
		First->Next = InsertNode;
	}

	void clear()
	{
		Node* Cur = First->Next;
		while (Cur != End)
		{
			Node* Temp = Cur->Next;

			delete Cur;
			Cur = Temp;
		}
		First->Next = End;
		End->Prev = First;
	}

	DataType& front()
	{
		if (First->Next == End)
		{
			MsgBoxAssert("list에 값이 들어있지 않은 상태입니다.");
		}
		return First->Next->Data;
	}

	DataType& back()
	{
		if (End->Prev == First)
		{
			MsgBoxAssert("list에 값이 들어있지 않은 상태입니다.");
		}
		return End->Prev->Data;
	}

	size_t size()
	{
		size_t Count = 0;
		Node* Temp = First;
		while (Temp->Next != End)
		{
			++Count;
			Temp = Temp->Next;
		}
		return Count;
	}

	iterator begin()
	{
		return iterator(First->Next);
	}
	iterator end()
	{
		return iterator(End);
	}

	iterator erase(iterator& _Iter)
	{
		iterator Result;
		if (nullptr != _Iter.CurNode)
		{
			Result = iterator(_Iter.CurNode->Next);

			_Iter.CurNode->Prev->Next = _Iter.CurNode->Next;
			Node* Test1 = _Iter.CurNode->Prev->Next;
			Node* Test2 = _Iter.CurNode->Next;

			_Iter.CurNode->Next->Prev = _Iter.CurNode->Prev;
			Node* Test3 = _Iter.CurNode->Next->Prev;
			Node* Test4 = _Iter.CurNode->Prev;

			delete _Iter.CurNode;
			_Iter.CurNode = nullptr;
		}
		return Result;
	}

protected:

private:
	Node* First = nullptr;
	Node* End = nullptr;
};