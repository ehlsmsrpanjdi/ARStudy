#pragma once

// 설명 :
template<typename DataType>
class YndooList
{
public:
	// constrcuter destructer
	YndooList()
	{
		Start = new Node();
		End = new Node();

		Start->Prev = nullptr;
		Start->Next = End;
		End->Prev = Start;
		End->Next = nullptr;
	}

	~YndooList()
	{
		while (Start != nullptr)
		{
			Node* Ptr = Start;
			Start = Start->Next;
			
			delete Ptr;
			Ptr = nullptr;
		}
	}

	class iterator;
	class Node {
	public:
		Node* Prev = nullptr;
		Node* Next = nullptr;
		DataType Data = DataType();

		void operator=(Node& _Other)
		{
			Prev = _Other->Prev;
			Next = _Other->Next;
			Data = _Other->Data;
		}

		/*void operator=(iterator _iter)
		{
			Prev = _iter->Prev;
			Next = _iter->Next;
			Data = *_iter;
		}*/
	};

	class iterator
	{
		friend class Node;
	public:
		iterator(Node* _CurNode)
			:CurNode(_CurNode)
		{

		}

		~iterator()
		{

		}

		Node* operator->()
		{
			return CurNode;
		}

		DataType operator*()
		{
			return CurNode->Data;
		}

		//DataType& operator*()
		//{
		//	return const_cast<DataType&>(CurNode->Data);
		//}

		//void operator++()		//전위
		//{
		//	CurNode = CurNode->Next;
		//}

		//void operator++(int)	//후위
		//{
		//	CurNode = CurNode->Next;
		//}

		iterator& operator++()		//전위
		{
			CurNode = CurNode->Next;
			return *this;
		}

		iterator& operator++(int)		//후위
		{
			CurNode = CurNode->Next;
			return *this;
		}


		iterator& operator--()		//전위
		{
			CurNode = CurNode->Prev;
			return *this;
		}

		iterator& operator--(int)	//후위
		{
			CurNode = CurNode->Prev;
			return *this;
		}

		bool operator!=(const iterator _Other)
		{
			return CurNode != _Other.CurNode;
		}

		Node* CurNode = nullptr;
	};

	class reverse_iterator
	{
	public:
		reverse_iterator(Node* _CurNode)
			:CurNode(_CurNode)
		{

		}

		~reverse_iterator()
		{

		}

		DataType& operator*()
		{
			return const_cast<DataType&>(CurNode->Data);
		}

		Node* operator->()
		{
			return CurNode;
		}

		reverse_iterator& operator++()		//전위
		{
			CurNode = CurNode->Prev;
			return *this;
		}

		reverse_iterator& operator++(int)		//후위
		{
			CurNode = CurNode->Prev;
			return *this;
		}


		reverse_iterator& operator--()		//전위
		{
			CurNode = CurNode->Next;
			return *this;
		}

		reverse_iterator& operator--(int)	//후위
		{
			CurNode = CurNode->Next;
			return *this;
		}

		bool operator!=(const reverse_iterator _Other)
		{
			return CurNode != _Other.CurNode;
		}
	private:
		Node* CurNode = nullptr;
	};

	DataType front()
	{
		return Start->Data;
	}

	iterator begin()
	{
		return iterator(Start->Next);
	}

	iterator end()
	{
		return iterator(End);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(End->Prev);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(Start);
	}

	void push_front(const DataType& _Data)
	{
		Node* NewNode = new Node();
		NewNode->Data = _Data;

		NewNode->Next = Start->Next;
		Start->Next->Prev = NewNode;
		Start->Next = NewNode;
		NewNode->Prev = Start;

		++list_size;
	}

	void push_back(const DataType& _Data)
	{
		Node* NewNode = new Node();
		NewNode->Data = _Data;

		NewNode->Prev = End->Prev;
		End->Prev->Next = NewNode;
		End->Prev = NewNode;
		NewNode->Next = End;

		++list_size;
	}

	void pop_front()
	{
		Node* Ptr = Start->Next;
		Start->Next->Next->Prev = Start;
		Start->Next = Start->Next->Next;
		delete Ptr;

		--list_size;
	}

	void pop_back()
	{
		Node* Ptr = End->Prev;
		End->Prev->Prev->Next = End;
		End->Prev = End->Prev->Prev;
		delete Ptr;

		--list_size;
	}

	void clear()
	{
		Node* Ptr = Start->Next;
		while (Ptr != End)
		{
			Start->Next = Start->Next->Next;

			delete Ptr;
			Ptr = nullptr;

			Ptr = Start->Next;
		}

		list_size = 0;
	}

	void erase(iterator where)
	{
		where.CurNode->Prev = where.CurNode->Next;
		where.CurNode->Next = where.CurNode->Prev;
		delete where.CurNode;
		where.CurNode = nullptr;

		--list_size;
	}

	void insert(iterator where, const DataType& _Data)
	{
		Node* Ptr = where.CurNode;
		Node* NewNode = new Node();
		NewNode->Data = _Data;

		Ptr->Prev->Next = NewNode;
		NewNode->Prev = Ptr->Prev;
		NewNode->Next = Ptr;
		Ptr->Prev = NewNode;

		++list_size;
	}

	void remove(const DataType& _Data)
	{
		Node* trash[100] = { nullptr };
		int trashNum = 0;
		for (YndooList<DataType>::iterator iter = begin(); iter != end(); ++iter)
		{
			if (*iter == _Data)
			{
				Node* FrontNode = (--iter).CurNode;
				++iter;	
				Node* NextNode = (++iter).CurNode;
				--iter;

				FrontNode->Next = NextNode;
				NextNode->Prev = FrontNode;

				trash[trashNum++] = iter.CurNode;
				--list_size;
			}
		}

		for (int i = 0; i < trashNum; i++)
		{
			delete trash[i];
			trash[i] = nullptr;
		} // 이게맞냐?..
	}

	size_t size()
	{
		return list_size;
	}

protected:

private:
	Node* Start;
	Node* End;

	size_t list_size = 0;
};

