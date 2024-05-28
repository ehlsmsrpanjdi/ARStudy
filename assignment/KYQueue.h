#pragma once


template<typename Type>
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
		
		// �����Ͱ� �ƿ� ���� ��
		if (nullptr == FirstNode && nullptr == LastNode)
		{
			FirstNode = NewNode;
			LastNode = NewNode;

		}
		else  // �����Ͱ� �� �� �̻��� ��
		{
			LastNode->NextNode = NewNode;
			NewNode->PrevNode = LastNode;
			LastNode = NewNode;
		}
	}

	inline void pop()
	{
		if (FirstNode == LastNode)
		{
			// �ƹ��͵� ���ٸ� ��ȯ (������ �Ͷ߷��� ��)
			if (nullptr == FirstNode)
			{
				return;
			}
			else   // �ϳ��� �������� ��
			{
				delete FirstNode;
				FirstNode = nullptr;
				LastNode = nullptr;
				return;
			}
		}
		else
		{
			// �ΰ� �̻� �������� ��
			QNode* ReleaseNode = FirstNode;

			FirstNode = FirstNode->NextNode;
			FirstNode->PrevNode = nullptr;

			delete ReleaseNode;
			ReleaseNode = nullptr;
		}
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




