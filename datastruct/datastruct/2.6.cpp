#include "2.6.h"


namespace Main_2_6
{
	Glist list_MakeEmpty(const ElementType index) //�������嵥Ԫ
	{
		Glist ptrl = new GNode();

		ptrl->tag = 1;
		ptrl->URegion.SybList = nullptr;
		ptrl->index = index;
		ptrl->Next = nullptr;

		return ptrl;
	}


	//ϵ����ָ��
	Glist indi_MakeEmpty(const ElementType coef, const ElementType index) //�������嵥Ԫ
	{
		Glist ptrl = new GNode();

		ptrl->tag = 0;
		ptrl->URegion.Data = coef;
		ptrl->index = index;
		ptrl->Next = nullptr;

		return ptrl;
	}


	Glist add_member_right(Glist ptrli, Glist ptr) //�б��������Ԫ��
	{
		if (ptr == nullptr)
		{
			return nullptr;
		}
		ptrli->Next = ptr;

		return ptr;
	}


	Glist add_member_down(Glist ptrli, Glist ptr) //������������Ԫ��
	{
		if (ptr == nullptr || ptrli->tag == 0) //�ǹ����
		{
			return nullptr;
		}
		ptrli->URegion.SybList = ptr;

		return ptr;
	}


	void print(Glist ptrl)			//��ӡ
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
		Glist P1 = list_MakeEmpty(12);			//����3��x�ĵ�Ԫ
		Glist P2 = list_MakeEmpty(8);
		Glist P3 = indi_MakeEmpty(3, 2);

		Glist list = add_member_down(P1, indi_MakeEmpty(9, 2));	//��x12�η��Ĺ������������������嵥Ԫ
		add_member_right(list, indi_MakeEmpty(4, 0));

		list = add_member_down(P2, indi_MakeEmpty(15, 3));	//��x8�η��Ĺ������������������嵥Ԫ
		add_member_right(list, indi_MakeEmpty(-1, 1));

		list = add_member_right(P1, P2);					//��p1 p2 p3��������
		list = add_member_right(list, P3);

		print(P1);										//��ӡ���ʽ (9y2 + 4y0)x12 + (15y3 - 1y1)x8 + 3x2

		return 0;
	}
}
