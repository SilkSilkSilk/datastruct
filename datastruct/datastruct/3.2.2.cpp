#include "3.2.2.h"

namespace Main_3_2_2
{ //二叉树基础操作

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
	}

	void main_3_2_2_new()
	{//任意两序构建树
		cout << "根据前序和中序创建二叉树a2" << endl;
		vector<int> s3 = { 1, 2, 4, 8, 3, 6, 12, 7, 15 };
		vector<int> s4 = { 8, 4, 2, 1, 12, 6, 3, 7, 15 };
		cout << "前序：" << endl;
		for (auto i : s3)
		{
			cout << i << ' ';
		}
		cout << endl << "中序：" << endl;
		for (auto i : s4)
		{
			cout << i << ' ';
		}

		class_3_2_2<int> a2(s3, s4, 0, 100); //建立二叉树

		cout << endl << "验证 a2堆栈前序：" << endl;
		a2.PreOrderTraversal_stack(a2.local_tree);



		cout << endl << "根据后序和中序创建二叉树a3" << endl;
		vector<int> s5 = { 8, 4, 2, 12, 6, 15, 7, 3, 1 };
		vector<int> s6 = { 8, 4, 2, 1, 12, 6, 3, 7, 15 };
		cout << "后序：" << endl;
		for (auto i : s5)
		{
			cout << i << ' ';
		}
		cout << endl << "中序：" << endl;
		for (auto i : s6)
		{
			cout << i << ' ';
		}

		class_3_2_2<int> a3(s5, s6, 1, 100); //建立二叉树

		cout << endl << "验证 a3堆栈中序：" << endl;
		a3.InOrderTraversal_stack(a3.local_tree);
	}

	void main_3_2_2_morphic()
	{//二叉树的同构
		cout << "根据后序和中序创建二叉树a1" << endl;
		vector<int> s1 = { 8, 4, 2, 12, 6, 15, 7, 3, 1 };
		vector<int> s2 = { 8, 4, 2, 1, 12, 6, 3, 7, 15 };
		class_3_2_2<int> a1(s1, s2, 1, 100); //建立二叉树

		cout << "a1 堆栈中序：" << endl;
		a1.InOrderTraversal_stack(a1.local_tree);

		cout << endl << endl << "根据后序和中序创建二叉树a2" << endl;
		vector<int> s3 = { 8, 4, 5, 2, 7, 3, 1 };
		vector<int> s4 = { 8, 4, 2, 5, 1, 3, 7 };
		class_3_2_2<int> a2(s3, s4, 1, 100); //建立二叉树

		cout << "a2 堆栈中序：" << endl;
		a2.InOrderTraversal_stack(a2.local_tree);

		cout << endl << "a1 a2 是否同构：" << endl;
		cout << a2.Is_morphic(a1.local_tree, a1.local_tree) << endl;
	}

	void main_3_2_2_morphic_new()
	{//二叉树的同构   Is_morphic和Isomorphic都可以判断同构，不过Isomorphic好像高效一些
		cout << "根据前序和中序创建二叉树a1" << endl;
		vector<char> s1 = { 'A', 'B', 'H', 'G', 'C', 'D', 'E' };
		vector<char> s2 = { 'G', 'H', 'B', 'A', 'D', 'C', 'E' };
		class_3_2_2<char> a1(s1, s2, 0, 100); //建立二叉树

		cout << "a1 堆栈中序：" << endl;
		a1.InOrderTraversal_stack(a1.local_tree);

		cout << endl << endl << "根据前序和中序创建二叉树a2" << endl;
		vector<char> s3 = { 'A', 'B', 'H', 'G', 'C', 'E', 'D' };
		vector<char> s4 = { 'B', 'G', 'H', 'A', 'E', 'C', 'D' };
		class_3_2_2<char> a2(s3, s4, 0, 100); //建立二叉树

		cout << "a2 堆栈中序：" << endl;
		a2.InOrderTraversal_stack(a2.local_tree);

		cout << endl << "a1 a2 是否同构：" << endl;
		cout << a2.Is_morphic(a1.local_tree, a2.local_tree) << endl;
	}
}
