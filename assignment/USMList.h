#pragma once


template <typename Type>
class USMItor
{
public:
	// constrcuter destructer
	USMItor(Type _Type)
		:Value(_Type)
	{
	}
	~USMItor() {

	}

	// delete Function
	USMItor(const USMItor& _Other) = delete;
	USMItor(USMItor&& _Other) noexcept = delete;
	USMItor& operator=(const USMItor& _Other) = delete;
	USMItor& operator=(USMItor&& _Other) noexcept = delete;


	void SetPrev(USMItor* _Prev) {
		if (nullptr != _Prev) {
			Prev->SetPrev(_Prev);
		}
		else {
			Prev = _Prev;
		}
	}

	void SetNext(USMItor* _Next) {
		if (nullptr != Next) {
			Next->SetNext(_Next);
		}
		else {
			Next = _Next;
		}
	}
	USMItor<Type>* Prev = nullptr;
	USMItor<Type>* Next = nullptr;
	Type Value;
};



template <typename Type>
class USMList
{
public:
	// constrcuter destructer
	USMList() {}
	~USMList();

	// delete Function
	USMList(const USMList& _Other) = delete;
	USMList(USMList&& _Other) noexcept = delete;
	USMList& operator=(const USMList& _Other) = delete;
	USMList& operator=(USMList&& _Other) noexcept = delete;

	void PushBack(Type _Type);
	void PushFront(Type _Type);
	USMItor<Type>* Begin();
	USMItor<Type>* End();
	int Size();

private:
	USMItor<Type>* Head = nullptr;
	USMItor<Type>* Tail = nullptr;
	int ListSize = 0;
};

template<typename Type>
inline void USMList<Type>::PushBack(Type _Type)
{
	++ListSize;
	USMItor<Type>* Node = new USMItor(_Type);
	if (nullptr == Head) {
		Head = Node;
	}

	if (nullptr == Tail) {
		Tail = Node;
	}
	else {
		Tail->SetNext(Node);
	}
}

template<typename Type>
inline void USMList<Type>::PushFront(Type _Type)
{
	++ListSize;
	USMItor<Type>* Node = new USMItor(_Type);
	if (nullptr == Head) {
		Head = Node;
	}
	else {
		Tail->SetPrev(Node);
	}
	if (nullptr == Tail) {
		Tail = Node;
	}
}

template<typename Type>
inline USMItor<Type>* USMList<Type>::Begin()
{
	return Head;
}

template<typename Type>
inline USMItor<Type>* USMList<Type>::End()
{
	return Tail;
}

template<typename Type>
inline int USMList<Type>::Size()
{
	return ListSize;
}
