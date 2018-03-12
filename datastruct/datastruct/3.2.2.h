#ifndef __MAIN_3_2_2_H__
#define __MAIN_3_2_2_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>


namespace Main_3_2_2
{	//链表实现二叉树存储
	using namespace std;


	template<class T> class class_3_2_2
	{
	public:
#define ERROR -1010
		typedef T ElementType;

		struct TreeNode
		{
			T Data;												//数据项
			shared_ptr<TreeNode> Left;							//二叉树左右指针
			shared_ptr<TreeNode> Right;
		};

		typedef shared_ptr<TreeNode> BinTree;					//智能指针管理内存
		BinTree local_tree;
		int Maxsize;

		void BinTree_Creat()			
		{
			local_tree = make_shared<TreeNode>();				//初始化智能指针 TreeNode默认构造

//			local_tree->Left = nullptr;							//这里不需要再次nullptr操作，因为TreeNode会执行默认初始化，指针默认初始化0，int默认初始化0
//			local_tree->Right = nullptr;
//			local_tree->Data = 0;
		}

		class_3_2_2(const int max_size = 1024)			//构造	初始化队列认	默认长度为1024
		{
			BinTree_Creat();
			Maxsize = max_size;
		}

		~class_3_2_2()
		{
			//析构
		}


	};

	void main_3_2_2();

}

#endif
