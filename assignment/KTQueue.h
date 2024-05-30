#pragma once
#include<iostream>
#include<queue>

template <typename DataType> class KTQueue;  // ����
namespace KT {

	template <typename DataType>
	class KTNode
	{
	public:
		KTNode() {

		}
		~KTNode() {

		}
		friend KTQueue; //� Ÿ������ �𸣴ϱ�
		DataType Data = DataType();
		KTNode<DataType>* NextNode = nullptr; //���ø��� Node<DataType>������ Ÿ���̴�.


	};

	template <typename DataType>
	class KTQueue
	{
	public:
		KTQueue()
		{
		}

		~KTQueue()
		{

		}
		void Push(DataType& _Data);
		void Pop(DataType& _Data);
	private:
		KTNode<DataType>* HeadNode = nullptr;
		KTNode<DataType>* TailNode = nullptr;



	};

	template<typename DataType>
	inline void KTQueue<DataType>::Push(DataType & _Data)
	{
		KTNode<DataType>* KTQ = new KTNode<DataType>(); //���ø����� � �����Ͱ� 
		KTQ->Data = _Data; //�����͸� �޾ƿ�


		if (nullptr == HeadNode)//���� startnode���� �𸣴� KTQ->StartNode
		{
			HeadNode = TailNode = KTQ;


			// ó���ε� 
			//�״��� NExtnode�� �ű���� �� ��ߵ�?
		}

		else if (HeadNode == TailNode)
		{

			TailNode = KTQ; //������ �׷��� ���ο� ��带 ����Ű��
			HeadNode->NextNode = TailNode; //����� ���� ���� ������ ����Ų��. 

		}

		else if (HeadNode != TailNode)
		{

			TailNode->NextNode = KTQ;
			TailNode = KTQ;


		}
	}

	template<typename DataType>
	inline void KTQueue<DataType>::Pop(DataType & _Data)
	{
		if (nullptr == HeadNode)
		{
			return; //�ƹ��͵� ���µ� ���� ����
		}
		else if (HeadNode == TailNode)
		{
			TailNode = nullptr;

		}
	}
}
