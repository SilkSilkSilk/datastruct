/*
二叉树的查找手段和数组类似，二叉树也有顺序查找，但是时间复杂度是节点个数，而二叉搜索树相当于数组的二分查找，这样时间复杂度只有树的高度。
二叉搜索树的插入：
二叉搜索树的删除：
*/
#include "4.1.h"

namespace Main_4_1
{
	void main_4_1()
	{
		cout << "根据先序和中序创建二叉树a1" << endl;
		vector<int> s1 = { 8, 3, 1, 6, 4, 7, 10, 14, 13 };
		vector<int> s2 = { 1, 3, 4, 6, 7, 8, 10, 13, 14 };
		class_4_1<int> a1(s1, s2, 0, 100); //建立二叉树

		cout << endl << "验证a1 堆栈中序：" << endl;
		a1.InOrderTraversal_stack(a1.local_tree);
			
		cout << endl << "a1中寻找8这个数据，返回元素的指针--递归--遍历所有节点, ";
		cout << "数据是否正确：" << ((a1.Bin_Find_Normal(a1.local_tree, 8) != nullptr ? a1.Bin_Find_Normal(a1.local_tree, 8)->Data : false) == 8 ? "正确" : "错误") << endl;

		cout << endl << "a1中寻找8这个数据，返回元素的指针--递归, ";
		cout << "数据是否正确：" << ((a1.Bin_Find(a1.local_tree, 8) != nullptr ? a1.Bin_Find(a1.local_tree, 8)->Data : false) == 8 ? "正确" : "错误") << endl;

		cout << endl << "a1中寻找8这个数据，返回元素的指针--while, ";
		cout << "数据是否正确：" << ((a1.Bin_Find_new(a1.local_tree, 8) != nullptr ? a1.Bin_Find_new(a1.local_tree, 8)->Data : false) == 8 ? "正确" : "错误") << endl;

		cout << endl << "a1中插入9这个数据，返回树头指针--递归, ";
		a1.Bin_Insert(a1.local_tree, 9);
		cout << "数据是否插入成功：" << ((a1.Bin_Find(a1.local_tree, 9) != nullptr ? a1.Bin_Find(a1.local_tree, 9)->Data : false) == 9 ? "成功" : "错误") << endl;

		cout << endl << "验证a1 堆栈中序：" << endl;
		a1.InOrderTraversal_stack(a1.local_tree);

		cout << endl << "a1中left方法删除6这个数据，返回树头指针--递归, ";
		a1.Bin_Delete_left(a1.local_tree, 6);
		cout << "数据是否删除成功：" << (a1.Bin_Find(a1.local_tree, 6) == nullptr ? "成功" : "错误") << endl;

		cout << endl << "验证a1 堆栈中序：" << endl;
		a1.InOrderTraversal_stack(a1.local_tree);

		cout << endl << "a1中right方法删除3这个数据，返回树头指针--递归, ";
		a1.Bin_Delete_right(a1.local_tree, 3);
		cout << "数据是否删除成功：" << (a1.Bin_Find(a1.local_tree, 3) == nullptr ? "成功" : "错误") << endl;

		cout << endl << "验证a1 堆栈中序：" << endl;
		a1.InOrderTraversal_stack(a1.local_tree);

		cout << endl << "a1中寻找最小值:";
		cout << a1.Bin_FindMin(a1.local_tree)->Data << endl;

		cout << "a1中寻找最大值:";
		cout << a1.Bin_FindMax(a1.local_tree)->Data << endl;
	}
}
