#pragma once

namespace ksw
{
	// 설명 : list 클래스

	template<typename Type>
	class list
	{
	private:
		struct Node
		{
			Node* Prev = nullptr;
			Node* Next = nullptr;
			Type Data;
		};

	public:
		// constructor destructor
		list() {};
		~list() {};

		// delete Function
		list(const list& _Other) = delete;
		list(list&& _Other) noexcept = delete;
		list& operator=(const list& _Other) = delete;
		list& operator=(list&& _Other) noexcept = delete;

	public:
		void push_back(Type _Data);


	private:
		Node* Begin = nullptr;
		Node* End = nullptr;

	};


	template<typename Type>
	inline void list<Type>::push_back(Type _Data)
	{
		Node* NewNode = new Node;
		NewNode->Data = _Data;

		if (nullptr == Begin)
		{
			Begin = NewNode;
		}
		else
		{
			NewNode->Prev = End;
		}

		End = NewNode;
	}


}

