#ifndef __MAIN_2_2_2_H__
#define __MAIN_2_2_2_H__

#include <iostream>
#include <vector>
#include <memory>


namespace Main_2_2_2
{	//单数组模拟堆栈
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

#endif
