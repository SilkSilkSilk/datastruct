#ifndef __MAIN_2_2_2_H__
#define __MAIN_2_2_2_H__

#include <iostream>
#include <vector>
#include <memory>


namespace Main_2_2_2
{	//单数组模拟一个堆栈
	using namespace std;

	typedef int ElementType;

	#define Max 1024
	#define ERROR -1010

//	typedef struct SNode *Stack;
	typedef shared_ptr<struct SNode> Stack;			//智能指针管理内存

	struct SNode
	{
		ElementType Data[Max];
		int Top;
	};

	Stack MakeEmpty();

	void Push(Stack ptr, ElementType t);		//入栈

	ElementType Pop(Stack ptrs);				//出栈
	
	int IsFull(Stack S);
	int IsEmpty(Stack S);
	void main_2_2_2();
}


namespace Main_2_2_2_tow
{	//单数组模拟两个堆栈
	using namespace std;

	typedef int ElementType;

#define Max 1024
#define ERROR -1010

	typedef shared_ptr<struct SNode> Stack;			//智能指针管理内存

	struct SNode
	{
		ElementType Data[Max];
		int Top1;
		int Top2;
	};

	Stack MakeEmpty();

	void Push(Stack ptr, const ElementType t, int tag);		//入栈

	ElementType Pop(Stack ptr, int tag);				//出栈

	int IsFull(Stack S);
	int IsEmpty_top1(Stack S);
	int IsEmpty_top2(Stack S);
	void main_2_2_2_tow();
}

#endif
