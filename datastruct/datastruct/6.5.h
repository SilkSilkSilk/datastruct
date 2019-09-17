#ifndef __MAIN_6_5_H__
#define __MAIN_6_5_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>


namespace Main_6_5
{	//二维数组实现图
	using namespace std;

	template<class T> class class_6_5
	{
	public:
		struct ENode
		{
			uint16_t V1, V2;	//v1 -> v2  可以表达又向图
			T weight;			//权重
		};
		typedef shared_ptr<struct ENode> PtrToNode;
		typedef PtrToNode Edge;

	public:
		class_6_5(uint16_t num);
		~class_6_5();
		Edge CreatEdge(uint16_t V1, uint16_t V2, T weight);
		void InsertEdge(Edge E);
		void print();

	private:
		#define Main_6_5_MaxSize 1000
		#define Main_6_5_Infinite 999
		int Nv;		//节点数
		int Ne;		//边数
		vector<shared_ptr<vector<shared_ptr<T>>>> VertexEdge;
	};

	template<class T>
	inline class_6_5<T>::class_6_5(uint16_t num)
	{
		if (num >= Main_6_5_MaxSize)
			return;

		for (int i = 0; i < num; i++)
		{
			shared_ptr<vector<shared_ptr<T>>> item = make_shared<vector<shared_ptr<T>>>();
			for (int j = 0; j < num; j++)
			{
				item->push_back(make_shared<T>(Main_6_5_Infinite));
			}
			VertexEdge.push_back(item);
		}
		Nv = num;
		Ne = 0;
	}

	template<class T>
	inline class_6_5<T>::~class_6_5()
	{
	}

	template<class T>
	inline typename class_6_5<T>::Edge class_6_5<T>::CreatEdge(uint16_t V1, uint16_t V2, T weight)
	{
		auto ret = make_shared<ENode>();
		ret->V1 = V1;
		ret->V2 = V2;
		ret->weight = weight > Main_6_5_Infinite ? Main_6_5_Infinite : weight;
		return ret;
	}

	template<class T>
	inline void class_6_5<T>::InsertEdge(Edge E)
	{
		if (E == nullptr || E->V1 >= Nv || E->V2 >= Nv)
			return;

		*VertexEdge[E->V1]->at(E->V2) = E->weight;
		Ne++;
		//无向图
		*VertexEdge[E->V2]->at(E->V1) = E->weight;
		Ne++;
	}

	template<class T>
	inline void class_6_5<T>::print()
	{
		cout << "" << "\t";
		for (int i = 0; i < VertexEdge.size(); i++)
		{
			cout << i << ":\t";
		}
		cout << endl;
		for (int i = 0; i < VertexEdge.size(); i++)
		{
			cout << i << ":\t";
			for (int j = 0; j < VertexEdge[i]->size(); j++)
			{
				if (*VertexEdge[i]->at(j) == Main_6_5_Infinite)
					cout << "-" << "\t";
				else
					cout << *VertexEdge[i]->at(j) << "\t";
			}
			cout << endl;
		}
	}

	void main_6_5();
}

#endif
