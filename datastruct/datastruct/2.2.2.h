#ifndef __MAIN_2_2_2_H__
#define __MAIN_2_2_2_H__

#include <iostream>
#include <vector>
#include <memory>


namespace Main_2_2_2
{	//������ģ���ջ
	using namespace std;

	typedef int ElementType;

	#define Max 1024
	#define ERROR -1010

//	typedef struct SNode *Stack;
	typedef shared_ptr<struct SNode> Stack;			//����ָ������ڴ�

	struct SNode
	{
		ElementType Data[Max];
		int Top;
	};

	Stack MakeEmpty();

	void Push(Stack ptr, ElementType t);		//��ջ

	ElementType Pop(Stack ptrs);				//��ջ
	
	int IsFull(Stack S);
	int IsEmpty(Stack S);
	void main_2_2_2();
}

#endif
