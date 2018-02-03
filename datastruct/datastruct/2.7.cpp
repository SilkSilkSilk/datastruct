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
		term[0].Down = nullptr;

		for (int i = 1; i <= nod; i++)
		{
			term[i].tag = 0;
			if(i == 1)
			{
				term[0].Right = &term[i];				//term头指向heard
			}
			else
			{
				term[i - 1].Urcvn.Next = &term[i];		//将head串起来
			}
			term[i].Down = &term[i];					//默认没有元素，所以头尾指针指向自己
			term[i].Right = &term[i];
		}

		term[nod].Urcvn.Next = &term[0];				//最后一个的next指向头
		
		for (int i = 0; i < m; i++)			//遍历vector
		{
			for (int j = 0; j < n; j++)
			{
				if (list[i][j] != 0)		//跳过0
				{
					InsertTerm(i, j, list[i][j]);
				}
			}
		}


		return &term[0];
	}

	bool InsertTerm(const int i, const int j, const int value)		//顺序添加方法
	{
//		MNode tm;										//临时变量会被销毁
//		shared_ptr<MNode> tm = make_shared<MNode>();	//智能指针不能传递给普通的指针
		MList tm = new MNode();
		
		tm->Urcvn.node.Row = i;
		tm->Urcvn.node.Col = j;
		tm->Urcvn.node.Value = value;

		//列操作
		MList ptr = &term[j + 1];
		while (ptr->Down != &term[j + 1])		//查看同列中要放入的元素之上是否有元素
		{
			ptr = ptr->Down;
		}
		ptr->Down = tm;
		tm->Down = &term[j + 1];


		//行操作
		ptr = &term[i + 1];
		while (ptr->Right != &term[i + 1])		//查看同列中要放入的元素之上是否有元素
		{
			ptr = ptr->Right;
		}
		ptr->Right = tm;
		tm->Right = &term[i + 1];

		return false;
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
