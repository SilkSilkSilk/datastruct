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
		typedef T ElementType;
		
		typedef shared_ptr<struct SNode> Stack;			//����ָ������ڴ�

		struct SNode
		{
			ElementType Data;
			Stack Next;
		};

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
//		Stack ptr(new SNode());			//ͷ��㲻���������൱��top = -1
		Stack ptr = make_shared<SNode>();
		ptr->next = nullptr;
		

		return ptr;
	}

	template<class T>
	inline void class_2_2_3<T>::Push(Stack ptr, ElementType t)
	{
		shared_ptr<SNode> ptr(new SNode());			//ͷ��㲻���������൱��top = -1
		
	}

	template<class T>
	inline typename class_2_2_3<T>::ElementType class_2_2_3<T>::Pop(Stack ptrs)
	{
		return ElementType();
	}

	template<class T>
	inline int class_2_2_3<T>::IsFull(Stack S)
	{
		return 0;
	}

	template<class T>
	inline int class_2_2_3<T>::IsEmpty(Stack S)
	{
		return 0;
	}

}

#endif
