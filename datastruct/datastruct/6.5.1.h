#ifndef __MAIN_6_5_1_H__
#define __MAIN_6_5_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>


namespace Main_6_5_1
{	//链表实现图
	using namespace std;

	template<class T> class class_6_5_1
	{
	public:
		struct VNode;
		typedef shared_ptr<VNode> PtrToVNode;
		struct VNode
		{
			uint16_t V;			//v1边
			T weight;			//权重
			PtrToVNode Next;	//next链表
		};

		struct ENode
		{
			uint16_t V1, V2;	//v1 -> v2  可以表达又向图
			T weight;			//权重
		};
		typedef shared_ptr<struct ENode> PtrToNode;
		typedef PtrToNode Edge;

	public:
		class_6_5_1(uint16_t num);
		~class_6_5_1();
		typename class_6_5_1<T>::Edge CreatEdge(uint16_t V1, uint16_t V2, T weight);
		void InsertEdge(Edge E);
		void print();

	private:
	#define Main_6_5_1_MaxSize 1000
	#define Main_6_5_1_Infinite 999
		int Nv;		//节点数
		int Ne;		//边数
		vector<PtrToVNode> VertexEdge;
	};

	template<class T>
	inline class_6_5_1<T>::class_6_5_1(uint16_t num)
	{
		if (num >= Main_6_5_1_MaxSize)
			return;

		for (uint16_t i = 0; i < num; i++)
		{
			PtrToVNode item = make_shared<VNode>();
			VertexEdge.push_back(item);
		}
		Nv = num;
		Ne = 0;
		for (uint16_t i = 0; i < num; i++)
		{
			VertexEdge[i]->Next = nullptr;
		}
	}

	template<class T>
	inline class_6_5_1<T>::~class_6_5_1()
	{
	}

	template<class T>
	inline typename class_6_5_1<T>::Edge class_6_5_1<T>::CreatEdge(uint16_t V1, uint16_t V2, T weight)
	{
		auto ret = make_shared<ENode>();
		ret->V1 = V1;
		ret->V2 = V2;
		ret->weight = weight > Main_6_5_1_Infinite ? Main_6_5_1_Infinite : weight;
		return ret;

	}

	template<class T>
	inline void class_6_5_1<T>::InsertEdge(Edge E)
	{
		if (E == nullptr || E->V1 >= Nv || E->V2 >= Nv)
			return;
		PtrToVNode newNode;

		//在V1中建立V2结点
		newNode = make_shared<VNode>();
		newNode->V = E->V2;
		newNode->weight = E->weight;
		newNode->Next = VertexEdge[E->V1]->Next;
		VertexEdge[E->V1]->Next = newNode;

		//若是无向图，在V2中建立V1结点
		newNode = make_shared<VNode>();
		newNode->V = E->V1;
		newNode->weight = E->weight;
		newNode->Next = VertexEdge[E->V2]->Next;
		VertexEdge[E->V2]->Next = newNode;
	}

	template<class T>
	inline void class_6_5_1<T>::print()
	{
		for (size_t i = 0; i < VertexEdge.size(); i++)
		{
			cout << "G[" << i << "] ->" << "\t";
			auto item = VertexEdge[i]->Next;
			while (item)
			{
				cout << item->V << " ->" << "\t";
				item = item->Next;
			}
			cout << "NULL" << endl;
		}
		cout << endl;
	}

	void main_6_5_1();
}

#endif
