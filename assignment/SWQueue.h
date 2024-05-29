#pragma once

namespace ksw
{
	template<typename Type>
	class queue
	{
	private:
		class Node
		{
		public:
			Node() {};
			Node(Type _Data) : Data(_Data) {};
			~Node() {};

		public:
			Node* Prev = nullptr;
			Node* Next = nullptr;
			Type Data = Type();
		};

	public:
		queue();
		~queue();

	public:
		inline Type& front();
		inline Type& back();

		inline void push(const Type& _Data);
		inline void pop();

		inline void clear();

		inline bool empty()
		{
			return 0 == Size;
		}

		inline size_t size()
		{
			return Size;
		}

	private:
		Node* Start = nullptr;
		Node* End = nullptr;

		size_t Size = 0;
	};

	// 구현부
	template<typename Type>
	inline queue<Type>::queue()
	{
		Start = new Node();
		End = new Node();

		Start->Next = End;
		End->Prev = Start;
	}

	template<typename Type>
	inline ksw::queue<Type>::~queue()
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
	inline Type& queue<Type>::front()
	{
		if (0 == Size)
		{
			MsgBoxAssert("비어있는 queue 입니다.");
		}

		return Start->Next->Data;
	}

	template<typename Type>
	inline Type& queue<Type>::back()
	{
		if (0 == Size)
		{
			MsgBoxAssert("비어있는 queue 입니다.");
		}

		return End->Prev->Data;
	}

	template<typename Type>
	inline void queue<Type>::push(const Type& _Data)
	{
		Node* NewNode = new Node(_Data);

		Node* PrevNode = End->Prev;
		PrevNode->Next = NewNode;
		End->Prev = NewNode;
		NewNode->Next = End;

		++Size;
	}

	template<typename Type>
	inline void queue<Type>::pop()
	{
		if (0 == Size)
		{
			MsgBoxAssert("비어있는 queue 입니다.");
		}

		Node* CurNode = Start->Next;
		Node* NextNode = CurNode->Next;

		Start->Next = NextNode;
		delete CurNode;

		--Size;
	}

	template<typename Type>
	inline void queue<Type>::clear()
	{
		Node* CurNode = Start->Next;

		while (End != CurNode)
		{
			Node* NextNode = CurNode->Next;
			delete CurNode;
			CurNode = NextNode;
		}

		Size = 0;
	}
}