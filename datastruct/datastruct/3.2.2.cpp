#include "3.2.2.h"

namespace Main_3_2_2
{ //链表实现二叉树存储

	void main_3_2_2()
	{
		const vector<int> s = {1, 2, 4, 8, null_Bin, null_Bin, null_Bin, null_Bin, 3, 6, 12, null_Bin, null_Bin, null_Bin, 7, null_Bin, 15, null_Bin, null_Bin};

		class_3_2_2<int> a(s, 100); //建立二叉树

		for (auto i : s)
		{
			cout << i << ' ';
		}

		cout << endl << "递归前序：" << endl;
		a.PreOrderTraversal(a.local_tree);

		cout << endl << "递归中序：" << endl;
		a.InOrderTraversal(a.local_tree);

		cout << endl << "递归后序：" << endl;
		a.PostOrderTraversal(a.local_tree);

		cout << endl << "堆栈前序：" << endl;
		a.PreOrderTraversal_stack(a.local_tree);

		cout << endl << "堆栈中序：" << endl;
		a.InOrderTraversal_stack(a.local_tree);

		cout << endl << "堆栈后序：" << endl;
		a.PostOrderTraversal_stack(a.local_tree);

		cout << endl << "层序遍历：" << endl;
		a.LevelOrderTraversal(a.local_tree);

		cout << endl << "树的高度：" << a.PostOrderGetHeight(a.local_tree) << endl;

		vector<int> s1 = {1, 2, 4, 8, 5, 3, 7};
		vector<int> s2 = {8, 4, 2, 5, 1, 3, 7};
		class_3_2_2<int> a1(s1, s2, 100); //建立二叉树

		cout << endl << "a1 堆栈前序：" << endl;
		a1.PreOrderTraversal_stack(a1.local_tree);


		vector<int> s3 = { 1, 2, 4, 8, 3, 6, 12, 7, 15 };
		vector<int> s4 = { 8, 4, 2, 1, 12, 6, 3, 7, 15 };
		class_3_2_2<int> a2(s3, s4, 100); //建立二叉树

		cout << endl << "a2 堆栈前序：" << endl;
		a2.PreOrderTraversal_stack(a2.local_tree);
	}
}
