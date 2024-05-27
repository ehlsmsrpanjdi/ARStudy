#pragma once

template <typename Type>
class Node {
public:
	Node(Type _Type)
		:Value(_Type)
	{

	}
private:
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

	}


private:
	Node<Type>* Head = nullptr;
	Node<Type>* Tail = nullptr;
	int QueueSize = 0;
};

