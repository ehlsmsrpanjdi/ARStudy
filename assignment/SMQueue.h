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

	}

	// delete Function
	SMQueue(const SMQueue& _Other) = delete;
	SMQueue(SMQueue&& _Other) noexcept = delete;
	SMQueue& operator=(const SMQueue& _Other) = delete;
	SMQueue& operator=(SMQueue&& _Other) noexcept = delete;

	void Push(Type _Type) {
		Node<Type>* NewNode = new Node(_Type);
		if (nullptr == Head) {
			Head = NewNode;
			Tail = NewNode;
		}
		else {
			Tail->Next = NewNode;
			Tail = NewNode;
		}
	}


private:
	Node<Type>* Head = nullptr;
	Node<Type>* Tail = nullptr;
	int QueueSize = 0;
};

