#pragma once

namespace SM {
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

		bool Empty() {
			return (QueueSize > 0) ? false : true;
		}

		void Swap(SMQueue<Type>& _Queue) {
			Node<Type>* NewNode = nullptr;
			NewNode = Head;
			Head = _Queue.Head;
			_Queue.Head = NewNode;

			NewNode = Tail;
			Tail = _Queue.Tail;
			_Queue.Tail = NewNode;

			int tempsize = QueueSize;
			QueueSize = _Queue.Size();
			_Queue.QueueSize = tempsize;

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

		void Pop() {
			--QueueSize;
			Node<Type>* Node = Head;
			Head = Head->Next;
			delete Node;
			if (0 == QueueSize) {
				Tail = nullptr;
				Head = nullptr;
			}
		}

		Type Front() {
			return Head->Value;
		}

		Type Back() {
			return Tail->Value;
		}

	private:
		Node<Type>* Head = nullptr;
		Node<Type>* Tail = nullptr;
		int QueueSize = 0;
	};

}