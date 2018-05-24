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
#define null_Bin 110011							//空节点

		struct TreeNode
		{
			T Data;												//数据项
			shared_ptr<TreeNode> Left;							//二叉树左右指针
			shared_ptr<TreeNode> Right;
		};

		typedef shared_ptr<TreeNode> BinTree;					//智能指针管理内存
		BinTree local_tree = nullptr;
		int BinTree_size = -1;
		int BinTree_Maxsize;

		void BinTree_Creat()
		{
			local_tree = make_shared<TreeNode>();

			local_tree->Left = nullptr;
			local_tree->Right = nullptr;
			local_tree->Data = 0;
		}

		//先序创建二叉树
		BinTree BinTree_Creat(const vector<int> &s)
		{
			++BinTree_size;
			BinTree bt;

			if (BinTree_size >= BinTree_Maxsize)
			{
				return nullptr;
			}
			else
			{
				if (s[BinTree_size] == null_Bin)
				{
					bt = nullptr;
				}
				else
				{
					bt = make_shared<TreeNode>();
					bt->Data = s[BinTree_size];
					bt->Left = BinTree_Creat(s);
					bt->Right = BinTree_Creat(s);
				}
			}
			return bt;
		}

		class_3_2_2(const vector<int> &s, const int max_size = 1024) : BinTree_size(-1)
		{
			BinTree_Maxsize = max_size;
			local_tree = BinTree_Creat(s);  //最后返回根
		}

		~class_3_2_2()
		{
			//析构
		}

		void PreOrderTraversal(BinTree bt)
		{
			if (bt != nullptr)
			{
				cout << bt->Data << ' ';
				PreOrderTraversal(bt->Left);
				PreOrderTraversal(bt->Right);
			}
		}

	};

	void main_3_2_2();

}

#endif
