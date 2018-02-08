#ifndef __MAIN_2_2_3_H__
#define __MAIN_2_2_3_H__

#include <iostream>
#include <vector>
#include <memory>


namespace Main_2_2_3
{	//ʹ��ģ����ʵ�ֲ���  ����ķ�ʽ���洢��ջ�������ڿռ��˷�
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

		typedef shared_ptr<SNode> Stack;			//����ָ������ڴ�

		int top;

		Stack MakeEmpty();

		void Push(Stack ptr, ElementType t);		//��ջ

		ElementType Pop(Stack ptrs);				//��ջ

		int IsFull(Stack S);
		int IsEmpty(Stack S);
		
	};

	void main_2_2_3();

	template<class T>
	typename class_2_2_3<T>::Stack class_2_2_3<T>::MakeEmpty()		//ʹ��typenameָ��Stack��һ�����ͣ���Ȼ��������ʶ��
	{
		Stack ptr(new SNode());			//ͷ��㲻���������൱��top = -1
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

		return p->Data;		//������֮��p�ļ���Ϊ��
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
