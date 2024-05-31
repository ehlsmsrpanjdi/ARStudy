#pragma once
#include<iostream>
#include<queue>

template <typename DataType> class KTQueue;  // 선언
namespace KT {

	template <typename DataType>
	class KTNode
	{
	public:
		KTNode() {

		}
		~KTNode() {

		}
		friend KTQueue; //어떤 타입인지 모르니까
		DataType Data = DataType();
		KTNode<DataType>* NextNode = nullptr; //템플릿은 Node<DataType>까지가 타입이다.


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
		KTNode<DataType>* KTQ = new KTNode<DataType>(); //템플릿에서 어떤 데이터가 
		KTQ->Data = _Data; //데이터를 받아와


		if (nullptr == HeadNode)//누구 startnode인지 모르니 KTQ->StartNode
		{
			HeadNode = TailNode = KTQ;


			// 처음인데 
			//그다음 NExtnode를 옮기려면 뭐 써야됨?
		}

		else if (HeadNode == TailNode)
		{

			TailNode = KTQ; //테일은 그러면 새로운 노드를 가르키고
			HeadNode->NextNode = TailNode; //헤드의 다음 노드는 테일을 가르킨다. 

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
			return; //아무것도 없는데 뺄수 없음
		}
		else if (HeadNode == TailNode)
		{
			TailNode = nullptr;

		}
	}
}
