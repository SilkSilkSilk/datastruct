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
		#define MaxData 1000	//max priority
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
		bool IsFull();
		bool IsEmpty();
		void print();
		void Insert(ElementType item);
		ElementType DeleteMax(bool* is_success);
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
	inline typename class_5_1<T>::Heap class_5_1<T>::Creat(int maxsize)
	{
		Heap heap = make_shared<HeapStruct>();
		heap->elements.push_back(make_shared<ElementType>(MaxData));

		for (auto i = 0; i < maxsize; i++)
		{
			heap->elements.push_back(make_shared<ElementType>(0));
		}
		
		heap->Size = 0;
		heap->Capacity = maxsize;
		return heap;
	}

	template<class T>
	inline bool class_5_1<T>::IsFull()
	{
		if (localheap->Size >= localheap->Capacity)
			return true;
		else
			return false;
	}

	template<class T>
	inline bool class_5_1<T>::IsEmpty()
	{
		if (localheap->Size <= 0)
			return true;
		else
			return false;
	}

	template<class T>
	inline void class_5_1<T>::print()		//层序遍历
	{
		if (IsEmpty())
		{
			cout << "heap is empty" << endl;
			return;
		}

		int h_l = -1;
		for (auto i = 1; i <= localheap->Size; i++)
		{
			if (localheap->elements[i] == nullptr)
				break;

			cout << *localheap->elements[i] << " ";

			int h = static_cast<int>(log(i + 1) / log(2));
			if (h != h_l)
			{
				cout << endl;
				h_l = h;
			}
		}
		cout << endl;
	}

	template<class T>
	inline void class_5_1<T>::Insert(ElementType item)
	{
		if (IsFull())
		{
			cout << "heap is full" << endl;
			return;
		}

		int i = ++localheap->Size;
		for (; *localheap->elements[i / 2] < item; i /= 2)
		{
			localheap->elements[i] = localheap->elements[i / 2];
		}
		localheap->elements[i] = make_shared<ElementType>(item);
	}

	template<class T>
	inline typename class_5_1<T>::ElementType class_5_1<T>::DeleteMax(bool* is_success)
	{
		if (IsEmpty())
		{
			if (is_success)
			{
				*is_success = false;
			}
			return ElementType();
		}

		int parent, child;
		ElementType Maxitem;
		Elementptr temp;

		Maxitem = *localheap->elements[1];
		*localheap->elements[1] = *localheap->elements[localheap->Size--];
		for (parent = 1; parent * 2 <= localheap->Size; parent = child)
		{
			child = parent * 2;
			if (child < localheap->Size && (*localheap->elements[child] < *localheap->elements[child + 1]))
			{
				child++;
			}
			
			if (*localheap->elements[parent] < *localheap->elements[child])
			{
				temp = localheap->elements[parent];
				localheap->elements[parent] = localheap->elements[child];
				localheap->elements[child] = temp;
			}
			else
			{
				break;
			}
		}

		*is_success = true;
		return Maxitem;
	}
	

	void main_5_1();
}

#endif