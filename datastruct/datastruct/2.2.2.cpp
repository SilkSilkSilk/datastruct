#include "2.2.2.h"


namespace Main_2_2_2
{
	Stack MakeEmpty()
	{
		Stack ptr(new SNode());
		ptr->Top = -1;

		return ptr;
	}


	void Push(Stack ptr, const ElementType t)
	{
		if (ptr->Top == Max - 1)
		{
			cout << "is full" << endl;
		}
		else
		{
			ptr->Data[++( ptr->Top )] = t; //ǰ׺ ���뵽��һ��λ��
		}
	}


	ElementType Pop(Stack ptrs)
	{
		if (ptrs->Top == -1)
		{
			cout << "no data" << endl;
			return ERROR;
		}
		return ptrs->Data[ptrs->Top--]; //��׺ ȥ����ǰλ��Ȼ��--
	}


	int IsFull(Stack S)
	{
		return S->Top == Max - 1 ? 1 : 0;
	}


	int IsEmpty(Stack S)
	{
		return S->Top == -1 ? 1 : 0;
	}


	void main_2_2_2()
	{
		auto a = MakeEmpty();

		Push(a, 1);
		Push(a, 2);
		Push(a, 3);

		cout << Pop(a) << endl;
		cout << Pop(a) << endl;
		cout << Pop(a) << endl;
		cout << Pop(a) << endl; //��ջ
	}
}


namespace Main_2_2_2_tow
{
	Stack MakeEmpty()
	{
		Stack ptr(new SNode());
		ptr->Top1 = -1; //��ͷ��ʼ
		ptr->Top2 = Max; //��β��ʼ

		return ptr;
	}


	void Push(Stack ptr, const ElementType t, const int tag)
	{
		if (ptr->Top2 - ptr->Top1 == 1)		//��ѯ��ջ���Ĳ���
		{
			cout << "is full" << endl;
		}
		else
		{
			if (tag == 0) //0��ʾtop1�Ķ�ջ
			{
				ptr->Data[++( ptr->Top1 )] = t;
			}
			else //��0��top2
			{
				ptr->Data[--( ptr->Top2 )] = t;
			}
		}
	}


	ElementType Pop(Stack ptr, const int tag)
	{
		if (tag == 0)
		{
			if (ptr->Top1 == -1)
			{
				cout << "top1 no data" << endl;
				return ERROR;
			}
			return ptr->Data[ptr->Top1--]; //��׺ ȥ����ǰλ��Ȼ��--
		}
		else
		{
			if (ptr->Top2 == Max)
			{
				cout << "top2 no data" << endl;
				return ERROR;
			}
			return ptr->Data[ptr->Top2++]; //��׺ ȥ����ǰλ��Ȼ��++
		}
	}


	int IsFull(Stack S)
	{
		return S->Top2 - S->Top1 == 1 ? 1 : 0;
	}


	int IsEmpty_top1(Stack S)
	{
		return S->Top1 == -1 ? 1 : 0;
	}


	int IsEmpty_top2(Stack S)
	{
		return S->Top2 == Max ? 1 : 0;
	}


	void main_2_2_2_tow()
	{
		auto a = MakeEmpty();

		Push(a, 1, 0);		//top1�м���1,2,3
		Push(a, 2, 0);
		Push(a, 3, 0);

		Push(a, 3, 1);		//top2�м���3,2,1
		Push(a, 2, 1);
		Push(a, 1, 1);

		cout << Pop(a, 0) << endl;	//3
		cout << Pop(a, 0) << endl;	//2
		cout << Pop(a, 0) << endl;	//1
		cout << Pop(a, 0) << endl;  //ȡ���ˣ���ջ

		cout << Pop(a, 1) << endl;	//1
		cout << Pop(a, 1) << endl;	//2
		cout << Pop(a, 1) << endl;	//3
		cout << Pop(a, 1) << endl;	//ȡ���ˣ���ջ
	}
}
