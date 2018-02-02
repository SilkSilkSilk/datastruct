#ifndef __MAIN_2_7_H__
#define __MAIN_2_7_H__

#include <iostream>
#include <vector>
#include <memory>


namespace Main_2_7
{//多重链表的矩阵实例运用
	using namespace std;

	typedef int ElementType;

	typedef struct MNode *MList;
	struct MNode
	{
		int tag;		//区分term和head类型，非0行列节点表示term, term = 1 
		MList Down;		//接受列指针，上下

		union
		{
			struct	//节点数据
			{
				int Row;	//行和列
				int Col;	
				int Value;	//数据
			}node;

			MList Next;
		}Urcvn;
		
		MList Right;		//接受右
	};

	#define Max_head 1024

	extern shared_ptr<MNode[]> term;

	MList Make_init(const vector<vector<int>> &list);

	int main_2_7();
}


#endif
