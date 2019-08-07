#ifndef __MAIN_5_1_H__
#define __MAIN_5_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>


namespace Main_5_1
{	//堆：数组实现完全二叉树
	using namespace std;

	struct Task		//模拟的任务
	{
		int priority;	//任务优先级
		string str;		//任务名
	};

	template<class T> class class_5_1
	{
	public:
		typedef T ElementType;
		typedef shared_ptr<ElementType> Elementptr;
		struct HeapStruct
		{
			vector<Elementptr> elements;	//array
			int Size;						//numbel
			int Capacity;					//total numbel
		};
		typedef shared_ptr<HeapStruct> Heap;
		Heap localheap;

		class_5_1(int maxsize);
		~class_5_1();
		Heap Creat(int maxsize);

	};

	template<class T>
	class_5_1<T>::class_5_1(int maxsize)
	{
		localheap = Creat(maxsize);
	}

	template<class T>
	inline class_5_1<T>::~class_5_1()
	{
	}

	template<class T>
	inline class_5_1<T>::Heap class_5_1<T>::Creat(int maxsize)
	{
		Heap heap = make_shared<HeapStruct>();
		heap->elements.resize(maxsize);
		heap->size = 0;
		heap->Capacity = maxsize;

		return heap;
	}

	void main_5_1();
}

#endif