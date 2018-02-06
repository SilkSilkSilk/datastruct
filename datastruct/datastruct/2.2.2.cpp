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
			ptr->Data[++(ptr->Top)] = t;
		}
	}

	ElementType Pop(Stack ptrs)
	{
		if (ptrs->Top == -1)
		{
			cout << "no data" << endl;
			return ERROR; 
		}
		else
		{
			return ptrs->Data[ptrs->Top--];
		}
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
		cout << Pop(a) << endl;		//¿ÕÕ»
	}



}