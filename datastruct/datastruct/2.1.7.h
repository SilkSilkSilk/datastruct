#ifndef __MAIN_2_1_7_H__
#define __MAIN_2_1_7_H__

#include <iostream>
#include <vector>
#include <memory>


namespace Main_2_1_7
{//��������ľ���ʵ������
	using namespace std;

	typedef int ElementType;

	typedef struct MNode *MList;
//	typedef shared_ptr<struct MNode> MList;

	struct MNode
	{
		int tag;		//����term��head���ͣ���0���нڵ��ʾterm, term = 1 
		MList Down;		//������ָ�룬����

		union
		{
			struct	//�ڵ�����
			{
				int Row;	//�к���
				int Col;	
				int Value;	//����
			}node;

			MList Next;
		}Urcvn;
		
		MList Right;		//������

		~MNode();
	};

	#define Max_head 1024

	extern shared_ptr<MNode[]> term;

	MList Make_init(const vector<vector<int>> &list);
	void InsertTerm(int i, int j, int value);
	void print(MList &ls);

	int main_2_1_7();
}


#endif
