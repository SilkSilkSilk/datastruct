#ifndef __MAIN_2_2_3_H__
#define __MAIN_2_2_3_H__

#include <iostream>
#include <vector>
#include <memory>


namespace Main_2_2_3
{	//使用模板类实现操作  链表的方式来存储堆栈，不存在空间浪费
	using namespace std;

	template<class T> class class_2_2_3
	{
	public:
		#define MAX 1024
		#define ERROR -1010
		typedef T ElementType;
		
		struct SNode
		{
			ElementType Data;
			shared_ptr<SNode> Next;
		};

		typedef shared_ptr<SNode> Stack;			//智能指针管理内存

		int top;

		Stack MakeEmpty();

		void Push(Stack ptr, ElementType t);		//入栈

		ElementType Pop(Stack ptrs);				//出栈

		int IsFull(Stack S);
		int IsEmpty(Stack S);
		
	};

	void main_2_2_3();

	template<class T>
	typename class_2_2_3<T>::Stack class_2_2_3<T>::MakeEmpty()		//使用typename指定Stack是一个类型，不然编译器不识别
	{
		Stack ptr(new SNode());			//头结点不保存数据相当于top = -1
		ptr->Next = nullptr;
		ptr->Data = ERROR;

		return ptr;
	}

	template<class T>
	inline void class_2_2_3<T>::Push(Stack ptr, ElementType t)
	{
		if (top >= MAX)
		{
			cout << "is full" << endl;
			return;
		}

		Stack p(new SNode());			
		p->Data = t;
		p->Next = ptr->Next;
		ptr->Next = p;

		top++;
	}

	template<class T>
	inline typename class_2_2_3<T>::ElementType class_2_2_3<T>::Pop(Stack ptr)
	{
		if (ptr->Next == nullptr)
		{
			cout << "no data" << endl;
			return ERROR;
		}

		Stack p = ptr->Next;

		ptr->Next = p->Next;
		top--;

		return p->Data;		//出函数之后p的计数为零
	}

	template<class T>
	inline int class_2_2_3<T>::IsFull(Stack S)
	{
		return top == MAX ? 1 : 0;
	}

	template<class T>
	inline int class_2_2_3<T>::IsEmpty(Stack S)
	{
		return S->Next == nullptr ? 1 : 0;
	}

}

#endif
