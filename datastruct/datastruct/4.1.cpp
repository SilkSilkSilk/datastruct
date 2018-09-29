#include "4.1.h"

namespace Main_4_1
{
	void main_4_1()
	{
		cout << "根据先序和中序创建二叉树a1" << endl;
		vector<int> s1 = { 8, 3, 1, 6, 4, 7, 10, 14, 13 };
		vector<int> s2 = { 1, 3, 4, 6, 7, 8, 10, 13, 14 };
		class_4_1<int> a1(s1, s2, 0, 100); //建立二叉树

		cout << "验证a1 堆栈中序：" << endl;
		a1.InOrderTraversal_stack(a1.local_tree);

		cout << endl << "a1中寻找8这个数据，返回元素的指针--递归, ";
		cout << "数据是否正确：" << (a1.Bin_Find(a1.local_tree, 8)->Data == 8 ? "正确":"错误") << endl;

		cout << endl << "a1中寻找8这个数据，返回元素的指针--while, ";
		cout << "数据是否正确：" << (a1.Bin_Find_new(a1.local_tree, 8)->Data == 8 ? "正确" : "错误") << endl;

		cout << endl << "a1中寻找最小值:";
		cout << a1.Bin_FindMin(a1.local_tree)->Data << endl;

		cout << "a1中寻找最大值:";
		cout << a1.Bin_FindMax(a1.local_tree)->Data << endl;
		
	}
}
