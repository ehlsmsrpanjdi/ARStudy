#pragma once

namespace ksw
{
	// 설명 : list 클래스

	template<typename Type>
	class list
	{
	private:
		class Node
		{
		public:
			Node* Prev = nullptr;
			Node* Next = nullptr;
			Type Data = Type();
		};

	public:
		class iterator
		{
			friend class list;
		public:
			iterator() {};

			iterator(Node* _CurNode)
				: CurNode(_CurNode)
			{};

			~iterator() {};

			inline iterator& operator++()
			{
				CurNode = CurNode->Next;
				return *this;
			}

			inline iterator operator++(Type)
			{
				iterator Result(CurNode);
				CurNode = CurNode->Next;
				return Result;
			}

			inline Type& operator*()
			{
				return CurNode->Data;
			}

			inline bool operator!=(const iterator& _Other)
			{
				return CurNode != _Other.CurNode;
			}

			inline bool operator==(const iterator& _Other)
			{
				return CurNode == _Other.CurNode;
			}

		private:
			Node* CurNode = nullptr;
		};

	public:
		// constructor destructor
		list();
		list(size_t _Size);
		list(Type _Data, size_t _Size);
		~list();

		// delete Function
		list(const list& _Other) = delete;
		list(list&& _Other) noexcept = delete;
		list& operator=(const list& _Other) = delete;
		list& operator=(list&& _Other) noexcept = delete;

	public:
		inline Type front();
		inline Type back();

		inline void push_front(const Type& _Data);
		inline void push_back(const Type& _Data);

		inline void pop_front();
		inline void pop_back();

		inline size_t remove(const Type& _Data);

		inline void clear();

		inline size_t size()
		{
			return Size;
		}

		inline bool empty()
		{
			return Size == 0;
		}

		// iterator
	public:
		inline iterator begin()
		{
			return iterator(Start->Next);
		}

		inline iterator end()
		{
			return iterator(End);
		}

		inline iterator insert(iterator& _Iter, const Type& _Data)
		{
			Node* NewNode = new Node();
			NewNode->Data = _Data;

			Node* CurNode = NewNode;
			Node* PrevNode = _Iter.CurNode->Prev;
			Node* NextNode = _Iter.CurNode;

			CurNode->Prev = PrevNode;
			CurNode->Next = NextNode;

			PrevNode->Next = CurNode;
			NextNode->Prev = CurNode;

			_Iter.CurNode = CurNode;

			++Size;
			return _Iter;
		}

		inline iterator erase(iterator& _Iter)
		{
			Node* CurNode = _Iter.CurNode;

			Node* NextNode = CurNode->Next;
			Node* PrevNode = CurNode->Prev;

			NextNode->Prev = PrevNode;
			PrevNode->Next = NextNode;

			delete CurNode;
			--Size;

			_Iter.CurNode = NextNode;
			if (End == _Iter.CurNode)
			{
				return nullptr;
			}

			return _Iter;
		}


	private:
		Node* Start = nullptr;
		Node* End = nullptr;
		size_t Size = 0;

	};

	// 구현부
	template<typename Type>
	inline list<Type>::list()
	{
		Start = new Node();
		End = new Node();

		Start->Next = End;
		End->Prev = Start;
	}

	template<typename Type>
	inline list<Type>::list(size_t _Size)
	{
		Start = new Node();
		End = new Node();

		Start->Next = End;
		End->Prev = Start;

		for (size_t i = 0; i < _Size; i++)
		{
			push_back(Type());
		}
	}

	template<typename Type>
	inline list<Type>::list(Type _Data, size_t _Size)
	{
		Start = new Node();
		End = new Node();

		Start->Next = End;
		End->Prev = Start;

		for (size_t i = 0; i < _Size; i++)
		{
			push_back(_Data);
		}
	}

	template<typename Type>
	inline ksw::list<Type>::~list()
	{
		Node* CurNode = Start;
		while (nullptr != CurNode)
		{
			Node* Next = CurNode->Next;
			delete CurNode;
			CurNode = Next;
		}
	}

	template<typename Type>
	inline Type list<Type>::front()
	{
		return Start->Next->Data;
	}

	template<typename Type>
	inline Type list<Type>::back()
	{
		return End->Prev->Data;
	}

	template<typename Type>
	inline void list<Type>::push_front(const Type& _Data)
	{
		Node* NewNode = new Node;
		NewNode->Data = _Data;

		Node* NextNode = Start->Next;
		Start->Next = NewNode;

		NewNode->Prev = Start;
		NewNode->Next = NextNode;
		NextNode->Prev = NewNode;

		++Size;
	}

	template<typename Type>
	inline void list<Type>::push_back(const Type& _Data)
	{
		Node* NewNode = new Node;
		NewNode->Data = _Data;

		Node* PrevNode = End->Prev;
		End->Prev = NewNode;

		NewNode->Prev = PrevNode;
		NewNode->Next = End;
		PrevNode->Next = NewNode;

		++Size;
	}

	template<typename Type>
	inline void list<Type>::pop_front()
	{
		Node* CurNode = Start->Next;
		Node* NextNode = CurNode->Next;

		Start->Next = NextNode;
		NextNode->Prev = Start;

		delete CurNode;
		--Size;
	}

	template<typename Type>
	inline void list<Type>::pop_back()
	{
		Node* CurNode = End->Prev;
		Node* PrevNode = CurNode->Prev;

		End->Prev = PrevNode;
		PrevNode->Next = End;

		delete CurNode;
		--Size;
	}

	template<typename Type>
	inline size_t list<Type>::remove(const Type& _Data)
	{
		size_t RemoveCount = 0;

		Node* CurNode = Start->Next;
		while (End != CurNode)
		{
			if (_Data == CurNode->Data)
			{
				Node* PrevNode = CurNode->Prev;
				Node* NextNode = CurNode->Next;

				PrevNode->Next = NextNode;
				NextNode->Prev = PrevNode;

				delete CurNode;
				CurNode = NextNode;

				--Size;
				++RemoveCount;
			}
			else
			{
				CurNode = CurNode->Next;
			}
		}

		return RemoveCount;
	}

	template<typename Type>
	inline void list<Type>::clear()
	{
		Node* CurNode = Start->Next;
		while (End != CurNode)
		{
			Node* NextNode = CurNode->Next;
			delete CurNode;
			CurNode = NextNode;
		}

		Start->Next = End;
		End->Prev = Start;

		Size = 0;
	}
}