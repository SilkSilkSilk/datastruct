#include "2.7.h"


namespace Main_2_7
{//�����������洢��ʵ��

	shared_ptr<MNode[]> term;

	MList Make_init(const vector<vector<int>> &list)
	{
		int m = list.size(), n = list[0].size();

//		cout << m << " " << n << endl;	//����vector��size�����õ�

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
				term[0].Right = &term[1];				//termͷָ��heard
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

	void InsertTerm(const int i, const int j, const int value)		//˳����ӷ������������£��������ң������ά����һ��
	{
//		MNode tm;										//��ʱ�����ᱻ����
//		shared_ptr<MNode> tm = make_shared<MNode>();	//����ָ�벻�ܴ��ݸ���ͨ��ָ��
		MList tm = new MNode();
		
		tm->Urcvn.node.Row = i;
		tm->Urcvn.node.Col = j;
		tm->Urcvn.node.Value = value;
		tm->tag = 1;

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
	}

	void print(MList & ls)				//ѭ�����ÿһ�е����ݣ�����row��col������ݵ�����
	{
		MList ptr = ls;
		MList pt = nullptr;

		int m = ptr->Urcvn.node.Row;
		int n = ptr->Urcvn.node.Col;

		vector<vector<int>> a(m, vector<int>(n,0));		//��ʼ��Ĭ�ϵľ���

		cout << "The list are " << ptr->Urcvn.node.Row << " rows and " << ptr->Urcvn.node.Col << " col,has " << ptr->Urcvn.node.Value << " data." <<endl;	//d��ӡ������
		ptr = ptr->Right;					//��termת��head

		while (ptr != ls)					//���и���head
		{
			pt = ptr;						//��head�洢
			while (ptr->Right != pt)		//����һ���е�ÿ��Ԫ��
			{
				ptr = ptr->Right;

				if (ptr->tag == 1)			//��ֹ��������ȷ����termԪ����ȡ����
				{
					a[ptr->Urcvn.node.Row][ptr->Urcvn.node.Col] = ptr->Urcvn.node.Value;	//���ݼ���vector��
				}
				else
				{
					cout << "errer data at print" << endl;
				}
			}
			ptr = pt->Urcvn.Next;			//���и���head
		}	
		for (auto i : a)					//��ӡ
		{
			for (auto j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}



	int main_2_7()		//��������ľ���ʵ������
	{
		const vector<vector<int>> a = {
			{18, 0, 0, 2, 0},
			{0, 27, 0, 0, 0},
			{0, 0, 0, -4, 0},
			{23, -1, 0, 0, 12}
		};

		cout << "the base data is:" << endl;
		for (auto i : a)
		{
			for (auto j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}
		cout << endl;

		auto b = Make_init(a);

		print(b);

		return 0;
	}
	MNode::~MNode()
	{
//		delete Down;
//		delete Right;

//		if (tag != 1)
//		{
//			delete Urcvn.Next;
//		}
	}
}
