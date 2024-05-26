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

			// 이거 수정 필요 할 듯
			inline void operator++()
			{
				CurNode = CurNode->Next;
			}

			// 이거 수정 필요 할 듯
			inline void operator--()
			{
				CurNode = CurNode->Prev;
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
		list() {};
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
			return iterator(Start);
		}

		inline iterator end()
		{
			if (0 == Size)
			{
				return nullptr;
			}

			return iterator(End->Next);
		}

		inline iterator insert(const iterator& _Iter, const Type& _Data)
		{
			return iterator();
		}

		inline iterator erase(iterator& _Iter)
		{
			Node* NextNode = _Iter.CurNode->Next;
			Node* PrevNode = _Iter.CurNode->Prev;
			
			if (Start == _Iter.CurNode)
			{
				if (nullptr != NextNode)
				{
					NextNode->Prev = nullptr;
				}
				else
				{
					End = nullptr;
				}
			
				Start = NextNode;
			}
			else if (End == _Iter.CurNode)
			{
				if (nullptr != PrevNode)
				{
					PrevNode->Next = nullptr;
				}
				else
				{
					Start = nullptr;
				}

				End = PrevNode;
			}
			else
			{
				NextNode->Prev = PrevNode;
				PrevNode->Next = NextNode;
			}
			
			delete _Iter.CurNode;
			--Size;

			_Iter.CurNode = NextNode;
			return _Iter;
		}


	private:
		Node* Start = nullptr;
		Node* End = nullptr;
		size_t Size = 0;

	};

	// 구현부
	template<typename Type>
	inline list<Type>::list(size_t _Size)
	{
		for (size_t i = 0; i < _Size; i++)
		{
			push_back(Type());
		}
	}

	template<typename Type>
	inline list<Type>::list(Type _Data, size_t _Size)
	{
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
		return Start->Data;
	}

	template<typename Type>
	inline Type list<Type>::back()
	{
		return End->Data;
	}

	template<typename Type>
	inline void list<Type>::push_front(const Type& _Data)
	{
		Node* NewNode = new Node;
		NewNode->Data = _Data;

		if (nullptr != Start)
		{
			NewNode->Next = Start;
			Start->Prev = NewNode;
		}

		Start = NewNode;
		++Size;
	}

	template<typename Type>
	inline void list<Type>::push_back(const Type& _Data)
	{
		Node* NewNode = new Node;
		NewNode->Data = _Data;

		if (nullptr == Start)
		{
			Start = NewNode;
		}
		else
		{
			End->Next = NewNode;
			NewNode->Prev = End;
		}

		End = NewNode;
		++Size;
	}

	template<typename Type>
	inline void list<Type>::pop_front()
	{
		Node* CurNode = Start;
		Start = CurNode->Next;
		Start->Prev = nullptr;
		delete CurNode;
		--Size;
	}

	template<typename Type>
	inline void list<Type>::pop_back()
	{
		Node* CurNode = End;
		End = CurNode->Prev;
		End->Next = nullptr;
		delete CurNode;
		--Size;
	}

	template<typename Type>
	inline void list<Type>::clear()
	{
		Node* CurNode = Start;
		while (nullptr != CurNode)
		{
			Node* NextNode = CurNode->Next;
			delete CurNode;
			CurNode = NextNode;
		}

		Start = nullptr;
		End = nullptr;
		Size = 0;
	}
}


