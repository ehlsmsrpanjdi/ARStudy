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
		if (Next != nullptr) {
			delete Next;
			Next = nullptr;
		}
	}

	// delete Function
	USMItor(const USMItor& _Other) = delete;
	USMItor(USMItor&& _Other) noexcept = delete;
	USMItor& operator=(const USMItor& _Other) = delete;
	USMItor& operator=(USMItor&& _Other) noexcept = delete;

	USMItor<Type>* Prev = nullptr;
	USMItor<Type>* Next = nullptr;
	Type Value;
	USMItor* operator++() {
		return Next;
	}

	USMItor operator++(int) {
		USMItor* Temp;
		Temp = this;
		 this = Next;
		return Temp;
	}
};



template <typename Type>
class USMList
{
public:
	// constrcuter destructer
	USMList() {}
	~USMList() {
		delete Head;
	}

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
	void Clear();
	bool Empty() {
		if (ListSize >= 1) {
			return false;
		}
		return true;
	}

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
		Tail = Node;
	}
	
	else if(Head == Tail){
		Tail = Node;
		Head->Next = Tail;
		Tail->Prev = Head;
	}

	else {
		Tail->Next = Node;
		Node->Prev = Tail;
		Tail = Node;
	}
}

template<typename Type>
inline void USMList<Type>::PushFront(Type _Type)
{
	++ListSize;
	USMItor<Type>* Node = new USMItor(_Type);
	if (nullptr == Head) {
		Head = Node;
		Tail = Node;
	}

	else if (Head == Tail) {
		Head = Node;
		Head->Next = Tail;
		Tail->Prev = Head;
	}

	else {
		Head->Prev = Node;
		Node->Next = Head;
		Head = Node;
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

template<typename Type>
inline void USMList<Type>::Clear()
{
	delete Head;
	Head = nullptr;
	Tail = nullptr;
	ListSize = 0;
}
