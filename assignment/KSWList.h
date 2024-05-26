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

			void operator++()
			{
				CurNode = CurNode->Next;
			}

			void operator--()
			{
				CurNode = CurNode->Prev;
			}

			Type& operator*()
			{
				return CurNode->Data;
			}

			bool operator!=(const iterator& _Other)
			{
				return CurNode != _Other.CurNode;
			}

			bool operator==(const iterator& _Other)
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
		Type front();
		Type back();

		void push_front(const Type& _Data);
		void push_back(const Type& _Data);

		void pop_front();
		void pop_back();

		inline size_t size()
		{
			return Size;
		}

		bool empty()
		{
			return Size == 0;
		}

	// iterator
	public:
		iterator begin()
		{
			return iterator(Start);
		}

		iterator end()
		{
			return iterator(End->Next);
		}

		iterator insert(const iterator& _Iter, const Type& _Data)
		{
			return iterator();
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
	}

	template<typename Type>
	inline void list<Type>::pop_back()
	{
		Node* CurNode = End;
		End = CurNode->Prev;
		End->Next = nullptr;
		delete CurNode;
	}
}


