#pragma once

template<typename DataType>
class JWList
{
private:
	struct Node
	{
		Node* Prev = nullptr;
		Node* Next = nullptr;
		DataType Data = DataType();
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
	//JWList& operator=(const JWList& _Other) = delete;
	JWList& operator=(JWList&& _Other) noexcept = delete;

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

		iterator& operator++()
		{
			CurNode = CurNode->Next;
			return *this;
		}

		DataType& operator*()
		{
			return CurNode->Data;
		}


	protected:

	private:
		Node* CurNode = nullptr;
	};

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
		if (_Iter.CurNode == First || _Iter.CurNode == End)
		{
			MsgBoxAssert("list에 값이 들어있지 않은 상태입니다.");
		}

		iterator Result;
		if (nullptr != _Iter.CurNode)
		{
			Result = iterator(_Iter.CurNode->Next);

			_Iter.CurNode->Prev->Next = _Iter.CurNode->Next;
			_Iter.CurNode->Next->Prev = _Iter.CurNode->Prev;

			delete _Iter.CurNode;
			_Iter.CurNode = nullptr;
		}
		return Result;
	}

	void insert(iterator& _Iter, DataType _Value)
	{
		Node* InsertNode = new Node();
		InsertNode->Data = _Value;

		InsertNode->Prev = _Iter.CurNode->Prev;
		InsertNode->Next = _Iter.CurNode;

		_Iter.CurNode->Prev->Next = InsertNode;
		_Iter.CurNode->Prev = InsertNode;
	}

	void operator=(const JWList& _OtherList)
	{
		Node* Temp = _OtherList.First->Next;
		while (Temp != _OtherList.End)
		{
			push_back(Temp->Data);
			Temp = Temp->Next;
		}
	}

	void remove(const DataType& _Value)
	{
		for (iterator Iter = this->begin(); Iter != this->end();)
		{
			if (Iter.CurNode->Data == _Value)
			{
				Iter = erase(Iter);
				continue;
			}
			++Iter;
		}
	}

protected:

private:
	Node* First = nullptr;
	Node* End = nullptr;
};