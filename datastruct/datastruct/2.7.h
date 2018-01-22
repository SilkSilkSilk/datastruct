#ifndef __MAIN_2_7_H__
#define __MAIN_2_7_H__

#include <iostream>
#include <vector>

namespace Main_2_7
{//��������ľ���ʵ������
	using namespace std;

	typedef int ElementType;

	typedef struct MNode *MList;
	struct MNode
	{
		int tag;		//����term��head���ͣ���0���нڵ��ʾterm
		MList Down;		//������ָ�룬����

		union
		{
			struct node		//�ڵ�����
			{
				int Row;	//�к���
				int Col;	
				int Value;	//����
			};

			MList Next;
		}Urcvn;
		
		MList Right;		//������
	};

	MList Make_init(const vector<vector<int>> &list);

	int main_2_7();
}


#endif
