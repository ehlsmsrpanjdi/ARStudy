#pragma once


typedef int Type;
//template<typename Type>
class KYQueue
{
private:
	class QNode
	{
		friend KYQueue;
	public:

	protected:

	private:
		Type Data = Type();
		QNode* PrevNode = nullptr;
		QNode* NextNode = nullptr;
	};

public:
	KYQueue()
	{

	}

	~KYQueue()
	{
		Release();
	}

	inline bool empty() const
	{
		if (nullptr == FirstNode && nullptr == LastNode)
		{
			return true;
		}

		return false;
	}


	inline void push(const Type& _Data)
	{
		QNode* NewNode = new QNode();
		NewNode->Data = _Data;
		
		// 데이터가 아예 없을 때
		if (nullptr == FirstNode && nullptr == LastNode)
		{
			FirstNode = NewNode;
			LastNode = NewNode;

		}
		else  // 데이터가 한 개 이상일 때
		{
			LastNode->NextNode = NewNode;
			NewNode->PrevNode = LastNode;
			LastNode = NewNode;
		}

		return;
	}
	

protected:

private:
	QNode* FirstNode = nullptr;
	QNode* LastNode = nullptr;

private:
	inline void Release()
	{
		while (nullptr != FirstNode)
		{
			QNode* ReleaseNode = FirstNode;

			FirstNode = FirstNode->NextNode;

			delete ReleaseNode;
			ReleaseNode = nullptr;
		}
	}
};




