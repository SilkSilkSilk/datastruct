#include "2.6.h"


namespace Main_2_6
{
	Glist list_MakeEmpty(const ElementType index) //建立广义单元
	{
		Glist ptrl = new GNode();

		ptrl->tag = 1;
		ptrl->URegion.SybList = nullptr;
		ptrl->index = index;
		ptrl->Next = nullptr;

		return ptrl;
	}


	//系数和指数
	Glist indi_MakeEmpty(const ElementType coef, const ElementType index) //建立个体单元
	{
		Glist ptrl = new GNode();

		ptrl->tag = 0;
		ptrl->URegion.Data = coef;
		ptrl->index = index;
		ptrl->Next = nullptr;

		return ptrl;
	}


	Glist add_member_right(Glist ptrli, Glist ptr) //列表向右添加元素
	{
		if (ptr == nullptr)
		{
			return nullptr;
		}
		ptrli->Next = ptr;

		return ptr;
	}


	Glist add_member_down(Glist ptrli, Glist ptr) //广域表向下添加元素
	{
		if (ptr == nullptr || ptrli->tag == 0) //非广域表
		{
			return nullptr;
		}
		ptrli->URegion.SybList = ptr;

		return ptr;
	}


	void print(Glist ptrl)			//打印
	{
		Glist ptr = ptrl;

		if (ptr == nullptr)
		{
			return;
		}

		while (ptr != nullptr)
		{
			if (ptr->tag == 1)
			{
				auto ptr1 = ptr->URegion.SybList;
				cout << "(";

				for (int i = 0; ptr1 != nullptr; ptr1 = ptr1->Next)
				{
					if (i != 0)
					{
						cout << ( ptr1->URegion.Data > 0 ? " + " : " - " );
					}
					cout << abs(ptr1->URegion.Data) << "y" << ptr1->index;
					i++;
				}

				cout << ")x" << ptr->index << " + ";
			}
			else
			{
				cout << ptr->URegion.Data << "x" << ptr->index;
			}
			ptr = ptr->Next;
		}
		cout << endl;
	}


	int main_2_6()
	{
		Glist P1 = list_MakeEmpty(12);			//建立3个x的单元
		Glist P2 = list_MakeEmpty(8);
		Glist P3 = indi_MakeEmpty(3, 2);

		Glist list = add_member_down(P1, indi_MakeEmpty(9, 2));	//在x12次方的广义表中中添加两个个体单元
		add_member_right(list, indi_MakeEmpty(4, 0));

		list = add_member_down(P2, indi_MakeEmpty(15, 3));	//在x8次方的广义表中中添加两个个体单元
		add_member_right(list, indi_MakeEmpty(-1, 1));

		list = add_member_right(P1, P2);					//将p1 p2 p3连接起来
		list = add_member_right(list, P3);

		print(P1);										//打印表达式 (9y2 + 4y0)x12 + (15y3 - 1y1)x8 + 3x2

		return 0;
	}
}
