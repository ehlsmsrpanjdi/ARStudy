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

		iterator begin()
		{
			return iterator(Begin);
		}

		iterator end()
		{
			return iterator(End->Next);
		}

		inline size_t size()
		{
			return Size;
		}

	private:
		Node* Begin = nullptr;
		Node* End = nullptr;
		size_t Size = 0;

	};

	// 구현부
	template<typename Type>
	inline ksw::list<Type>::~list()
	{
		Node* CurNode = Begin;
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
		return Begin->Data;
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

		if (nullptr != Begin)
		{
			NewNode->Next = Begin;
			Begin->Prev = NewNode;
		}

		Begin = NewNode;
		++Size;
	}

	template<typename Type>
	inline void list<Type>::push_back(const Type& _Data)
	{
		Node* NewNode = new Node;
		NewNode->Data = _Data;

		if (nullptr == Begin)
		{
			Begin = NewNode;
		}
		else
		{
			End->Next = NewNode;
			NewNode->Prev = End;
		}

		End = NewNode;
		++Size;
	}

}


