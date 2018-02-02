#include "2.7.h"


namespace Main_2_7
{//多重链表矩阵存储的深入理解，思路已经清晰

	shared_ptr<MNode[]> term;

	MList Make_init(const vector<vector<int>> &list)
	{
		int m = list.size(), n = list[0].size();

		cout << m << " " << n << endl;

		int nod = m > n ? m : n;		//取最大行列的最大数

		if (nod >= Max_head)
		{
			return nullptr;		//表错误
		}

//		MList term = new MNode[nod + 1]();
		shared_ptr<MNode[]> tm(new MNode[nod + 1]());
		term = tm;
//		shared_ptr<MNode[]> term = make_shared<MNode[3 + 1]>();  //这种方式不能用nod变量

		term[0].tag = 1;
		term[0].Urcvn.node.Row = m;		//行和列
		term[0].Urcvn.node.Col = n;

		for (int i = 1; i <= nod; i++)
		{
			if(i == 1)
			{
				term[0].Right = &term[i];
			}
			else
			{
				term[i - 1].Urcvn.Next = &term[i];
			}
			term[i].Down = &term[i];
			term[i].Right = &term[i];
		}

		term[nod].Urcvn.Next = &term[0];
		
		for (int i = 0; i < m; i++)			//遍历vector
		{
			for (int j = 0; j < n; j++)
			{

			}
		}


		return &term[0];
	}


	int main_2_7()		//多重链表的矩阵实例运用
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
}
