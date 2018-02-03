#include "2.7.h"


namespace Main_2_7
{//�����������洢��������⣬˼·�Ѿ�����

	shared_ptr<MNode[]> term;

	MList Make_init(const vector<vector<int>> &list)
	{
		int m = list.size(), n = list[0].size();

		cout << m << " " << n << endl;

		int nod = m > n ? m : n;		//ȡ������е������

		if (nod >= Max_head)
		{
			return nullptr;		//�����
		}

//		MList term = new MNode[nod + 1]();
		shared_ptr<MNode[]> tm(new MNode[nod + 1]());
		term = tm;
//		shared_ptr<MNode[]> term = make_shared<MNode[3 + 1]>();  //���ַ�ʽ������nod����

		term[0].tag = 1;
		term[0].Urcvn.node.Row = m;		//�к���
		term[0].Urcvn.node.Col = n;
		term[0].Down = nullptr;

		for (int i = 1; i <= nod; i++)
		{
			term[i].tag = 0;
			if(i == 1)
			{
				term[0].Right = &term[i];				//termͷָ��heard
			}
			else
			{
				term[i - 1].Urcvn.Next = &term[i];		//��head������
			}
			term[i].Down = &term[i];					//Ĭ��û��Ԫ�أ�����ͷβָ��ָ���Լ�
			term[i].Right = &term[i];
		}

		term[nod].Urcvn.Next = &term[0];				//���һ����nextָ��ͷ
		
		for (int i = 0; i < m; i++)			//����vector
		{
			for (int j = 0; j < n; j++)
			{
				if (list[i][j] != 0)		//����0
				{
					InsertTerm(i, j, list[i][j]);
				}
			}
		}


		return &term[0];
	}

	bool InsertTerm(const int i, const int j, const int value)		//˳����ӷ���
	{
//		MNode tm;										//��ʱ�����ᱻ����
//		shared_ptr<MNode> tm = make_shared<MNode>();	//����ָ�벻�ܴ��ݸ���ͨ��ָ��
		MList tm = new MNode();
		
		tm->Urcvn.node.Row = i;
		tm->Urcvn.node.Col = j;
		tm->Urcvn.node.Value = value;

		//�в���
		MList ptr = &term[j + 1];
		while (ptr->Down != &term[j + 1])		//�鿴ͬ����Ҫ�����Ԫ��֮���Ƿ���Ԫ��
		{
			ptr = ptr->Down;
		}
		ptr->Down = tm;
		tm->Down = &term[j + 1];


		//�в���
		ptr = &term[i + 1];
		while (ptr->Right != &term[i + 1])		//�鿴ͬ����Ҫ�����Ԫ��֮���Ƿ���Ԫ��
		{
			ptr = ptr->Right;
		}
		ptr->Right = tm;
		tm->Right = &term[i + 1];

		return false;
	}


	int main_2_7()		//��������ľ���ʵ������
	{
		const vector<vector<int>> a = {
			{18, 0, 0, 2, 0},
			{0, 27, 0, 0, 0},
			{0, 0, 0, -4, 0},
			{23, -1, 0, 0, 12}
		};

		Make_init(a);

		

		return 0;
	}
	MNode::~MNode()
	{
		delete Down;
		delete Right;

//		if (tag != 1)
//		{
//			delete Urcvn.Next;
//		}
	}
}
