#pragma once
namespace cjw
{
	template<typename DataType>
	class queue
	{
	private:
		struct Node
		{
		public:
			Node* Prev = nullptr;
			Node* Next = nullptr;
			DataType Data = DataType();
		};

	public:
		queue()
		{
			Front = new Node();
			Back = new Node();
			Front->Next = Back;
			Back->Prev = Front;
		}
		~queue() 
		{
			Node* Temp = Front->Next;
			while (Temp != Back)
			{
				delete Front->Next;
				Front->Next = nullptr;

				Temp = Temp->Next;
				Front->Next = Temp;
				Temp->Prev = Front;
			}

			delete Front;
			Front = nullptr;

			delete Back;
			Back = nullptr;
		}

		void push(DataType _Value)
		{
			Node* InsertNode = new Node();
			InsertNode->Data = _Value;

			InsertNode->Prev = Back->Prev;
			InsertNode->Next = Back;

			Back->Prev->Next = InsertNode;
			Back->Prev = InsertNode;
		}

		void pop()
		{
			Node* Temp = Front->Next->Next;

			delete Front->Next;
			Front->Next = nullptr;

			Front->Next = Temp;
			Temp->Prev = Front;
		}

		bool empty()
		{
			if (Front->Next == Back)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		size_t size()
		{
			size_t CountResult = 0;
			Node* IterNode = Front;
			while (true)
			{
				if (IterNode->Next == Back)
				{
					break;
				}
				CountResult++;
				IterNode = IterNode->Next;
			}
			return CountResult;
		}

		DataType& front()
		{
			return Front->Next->Data;
		}

		DataType& back()
		{
			return Back->Prev->Data;
		}

		void swap(queue& _Other)
		{
			while (Front->Next != Back)
			{
				pop();
			}

			while (false == _Other.empty())
			{
				push(_Other.front());
				_Other.pop();
			}
		}

	protected:

	private:
		Node* Front = nullptr;
		Node* Back = nullptr;
	};
}