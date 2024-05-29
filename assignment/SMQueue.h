#pragma once

template <typename Type>
class Node {
	template<typename Type> friend class SMQueue;
public:
	Node(Type _Type)
		:Value(_Type)
	{

	}

	~Node() {

	}
private:
	void NodeRelease() {
		if (nullptr != Next) {
			Next->NodeRelease();
			delete Next;
			Next = nullptr;
		}
	}
	Node<Type>* Next = nullptr;
	Type Value;
};

// Ό³Έν :
template <typename Type>
class SMQueue
{
public:
	// constrcuter destructer
	SMQueue() {

	}
	~SMQueue() {
		if (Head != nullptr) {
			Head->NodeRelease();
			delete Head;
		}
	}

	// delete Function
	SMQueue(const SMQueue& _Other) = delete;
	SMQueue(SMQueue&& _Other) noexcept = delete;
	SMQueue& operator=(const SMQueue& _Other) = delete;
	SMQueue& operator=(SMQueue&& _Other) noexcept = delete;

	int Size() {
		return QueueSize;
	}

	void Push(Type _Type) {
		Node<Type>* NewNode = new Node(_Type);
		++QueueSize;
		if (nullptr == Head) {
			Head = NewNode;
			Tail = NewNode;
		}
		else if (Head == Tail) {
			Head->Next = NewNode;
			Tail = NewNode;
		}
		else {
			Tail->Next = NewNode;
			Tail = NewNode;
		}
	}

	Type Pop() {
		--QueueSize;
		Type Temp = Head->Value;
		Node<Type>* Node = Head;
		Head = Head->Next;
		delete Node;
		if (0 == QueueSize) {
			Tail = nullptr;
			Head = nullptr;
		}
		return Temp;
	}

private:
	Node<Type>* Head = nullptr;
	Node<Type>* Tail = nullptr;
	int QueueSize = 0;
};

