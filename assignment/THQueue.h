#pragma once

template<typename DataType>
class THQueue
{
private:
	class Node
	{
		Node* Front = nullptr;
		Node* Back = nullptr;
		DataType Value;
	};

public:
	THQueue()
	{
		Front = new Node();
		Back = new Node();
	}

	~THQueue()
	{

	}

	void empty() 
	{

	}

	void size()
	{

	}

	void front()
	{

	}

	void back()
	{

	}

	void push()
	{

	}

	void emplace()
	{

	}

	void pop()
	{

	}

	void swap()
	{

	}

protected:

private:
	Node* Front = nullptr;
	Node* Back = nullptr;
	DataType Value;
};