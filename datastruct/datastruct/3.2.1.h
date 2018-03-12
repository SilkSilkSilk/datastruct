#ifndef __MAIN_3_2_1_H__
#define __MAIN_3_2_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>


namespace Main_3_2_1
{	//数组实现二叉树存储
	using namespace std;


	template<class T> class class_3_2_1
	{
	public:
		#define ERROR -1010
		typedef T ElementType;

		struct TreeNode
		{
			shared_ptr<T[]> Data;							//shared_ptr<T[]>表示Data是指向数组类型的
			int len;		//长度
		};

		typedef shared_ptr<TreeNode> BinTree;					//智能指针管理内存
		BinTree local_tree;
		int Maxsize;

		void BinTree_Creat(const int max_size)				//树的大小
		{
			local_tree = make_shared<TreeNode>();			//初始化智能指针
			local_tree->len = max_size;

			shared_ptr<T[]> tem(new T[max_size]());			//表示tem是指向数组类型的智能指针被默认初始化，具体初始化内容是T实现的
			local_tree->Data = tem;
			Maxsize = max_size;
		}

		class_3_2_1(const int max_size = 1024)			//构造	初始化队列认	默认长度为1024
		{
			BinTree_Creat(max_size);
		}

		~class_3_2_1()
		{
			//析构
		}


	};

	void main_3_2_1();

}

#endif
