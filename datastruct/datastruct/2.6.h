#ifndef __MAIN_2_6_H__
#define __MAIN_2_6_H__

#include <iostream>


namespace Main_2_6
{//������Ӧ��
	using namespace std;

	typedef int ElementType;

	typedef struct GNode *Glist;
	struct GNode
	{
		int tag;		//1��ʾ�����,0��ʾ��Ԫ��
		union
		{
			ElementType Data;
			Glist SybList;
		}URegion;
		ElementType index;
		Glist Next;
	};

	Glist list_MakeEmpty(const ElementType index);		//�������嵥Ԫ
	Glist indi_MakeEmpty(const ElementType coef, const ElementType index);		//�������嵥Ԫ

//	int length(Glist ptrl);

//	Glist insert(Glist ptrl, const bool i, const ElementType x);
	Glist add_member_right(Glist ptrli, Glist ptr);
	Glist add_member_down(Glist ptrli, Glist ptr);

//	Glist Delete(const int i, Glist ptrl);
	void print(Glist ptrl);
	int main_2_6();
}


#endif
