#include "3.2.2.h"

namespace Main_3_2_2
{	//链表实现二叉树存储

	void main_3_2_2()
	{
		const vector<int> s = { 1, 2, 4, 8, null_Bin, null_Bin, null_Bin, null_Bin, 3, 6, 12, null_Bin, null_Bin, null_Bin, 7, null_Bin, 15, null_Bin, null_Bin };

		class_3_2_2<int> a(s, 100);			//建立空的二叉树

		for(auto i : s)
		{
			cout << i << ' ';
		}
		cout << endl;

		cout << "前序遍历：" << endl;
		
		a.PreOrderTraversal(a.local_tree);
	}

}
