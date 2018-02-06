#include "2.1.2.h"
#include <iostream>


namespace Main_2_1_2
{
	List MakeEmpty()
	{
		List ptrL = nullptr;
		ptrL = new LNode();
		ptrL->Last = -1;
		return ptrL;
	}


	int Find(const ElementType x, const List ptrl)
	{
		if (ptrl == nullptr || ptrl->Last == -1)
			return -1;

		for (int i = 0; i < ptrl->Last; i++)
		{
			if (ptrl->Data[i] == x)
			{
				return i;
			}
		}
		return -1;
	}


	//���뵽iλ�õ�ǰ��
	//i�Ǵ�0��ʼ��
	void insert(const ElementType x, const int i, List const ptrl)
	{
		if (ptrl->Last >= MAXSIZE - 1)
		{
			return;
		}

		if (i < 0 || i > ptrl->Last + 1)
		{
			return;
		}

		for (int j = ptrl->Last; j > i; j--)
		{
			ptrl->Data[j + 1] = ptrl->Data[j];
		}

		ptrl->Data[i] = x;
		ptrl->Last++;
	}


	//i�Ǵ�0��ʼ��
	void Delete(const int i, List const ptrl)
	{
		if (i < 0 || i > ptrl->Last)
		{
			std::cout << "post is not exist" << std::endl;
			return;
		}

		for (int j = i; j < ptrl->Last; j++)
		{
			ptrl->Data[j] = ptrl->Data[j + 1];
		}

		ptrl->Last--;
	}


	void print(List const ptrl)
	{
		if (ptrl == nullptr || ptrl->Last == -1)
			return;

		for (int i = 0; i <= ptrl->Last; i++)
		{
			std::cout << ptrl->Data[i];
		}

		std::cout << std::endl;
	}


	int main_2_1_2()		//���Ա����
	{
		List ptrl = MakeEmpty();
		insert(1, 0, ptrl);
		insert(2, 1, ptrl);
		insert(3, 2, ptrl);
		print(ptrl);

		Delete(0, ptrl);
		print(ptrl);

		Delete(1, ptrl);
		print(ptrl);

		return 0;
	}
}
