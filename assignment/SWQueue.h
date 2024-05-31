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
			Node* Next = nullptr;
			Type Data = Type();
		};

	public:
		queue() {};
		~queue();

	public:
		inline Type& front();
		inline Type& back();

		inline void push(const Type& _Data);
		inline void pop();

		inline void swap(queue& _Other);
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
		Node* Head = nullptr;
		Node* Tail = nullptr;

		size_t Size = 0;
	};

	// 구현부
	template<typename Type>
	inline ksw::queue<Type>::~queue()
	{
		clear();
	}

	template<typename Type>
	inline Type& queue<Type>::front()
	{
		if (0 == Size)
		{
			MsgBoxAssert("비어있는 queue 입니다.");
		}

		return Head->Data;
	}

	template<typename Type>
	inline Type& queue<Type>::back()
	{
		if (0 == Size)
		{
			MsgBoxAssert("비어있는 queue 입니다.");
		}

		return Tail->Data;
	}

	template<typename Type>
	inline void queue<Type>::push(const Type& _Data)
	{
		Node* NewNode = new Node(_Data);

		if (0 == Size)
		{
			Head = NewNode;
			Tail = NewNode;
		}
		else if (1 == Size)
		{
			Tail = NewNode;
			Head->Next = Tail;
		}
		else
		{
			Tail->Next = NewNode;
			Tail = NewNode;
		}

		++Size;
	}

	template<typename Type>
	inline void queue<Type>::pop()
	{
		if (0 == Size)
		{
			MsgBoxAssert("비어있는 queue 입니다.");
		}
		else if (1 == Size)
		{
			delete Head;
			Head = nullptr;
			Tail = nullptr;
		}
		else
		{
			Node* CurNode = Head;
			Head = CurNode->Next;
			delete CurNode;
		}

		--Size;
	}

	template<typename Type>
	inline void queue<Type>::swap(queue& _Other)
	{
		Node* OtherHead = _Other.Head;
		Node* OtherTail = _Other.Tail;
		size_t OtherSize = _Other.Size;

		_Other.Head = Head;
		_Other.Tail = Tail;
		_Other.Size = Size;

		Head = OtherHead;
		Tail = OtherTail;
		Size = OtherSize;
	}

	template<typename Type>
	inline void queue<Type>::clear()
	{
		while (0 != Size)
		{
			pop();
		}
	}
}