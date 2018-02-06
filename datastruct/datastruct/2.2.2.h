#ifndef __MAIN_2_2_2_H__
#define __MAIN_2_2_2_H__

#include <iostream>
#include <vector>
#include <memory>


namespace Main_2_2_2
{	//������ģ��һ����ջ
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


namespace Main_2_2_2_tow
{	//������ģ��������ջ
	using namespace std;

	typedef int ElementType;

#define Max 1024
#define ERROR -1010

	typedef shared_ptr<struct SNode> Stack;			//����ָ������ڴ�

	struct SNode
	{
		ElementType Data[Max];
		int Top1;
		int Top2;
	};

	Stack MakeEmpty();

	void Push(Stack ptr, const ElementType t, int tag);		//��ջ

	ElementType Pop(Stack ptr, int tag);				//��ջ

	int IsFull(Stack S);
	int IsEmpty_top1(Stack S);
	int IsEmpty_top2(Stack S);
	void main_2_2_2_tow();
}

#endif
