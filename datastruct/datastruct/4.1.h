#ifndef __MAIN_4_1_H__
#define __MAIN_4_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>

#include "3.2.2.h"

namespace Main_4_1
{
	using namespace std;
	using namespace Main_3_2_2;

	template<class T> class class_4_1 : public Main_3_2_2::class_3_2_2<T>
	{
	public:
		//先序创建二叉树
		class_4_1(const vector<T> &s, const int max_size = 1024) :class_3_2_2(s, max_size)
		{

		}

		//先序(后序)和中序创建二叉树  0为先序+中序  1为后序+中序
		class_4_1(vector<T> &s1, vector<T> &s2, const int a, const int max_size = 1024) :class_3_2_2(s1, s2, a, max_size)
		{

		}

		~class_4_1()
		{
			
		}

		BinTree Bin_Find(BinTree bt, const T X)		//递归-二叉搜索树
		{
			if (!bt)
				return nullptr;

			if (X < bt->Data)		//小于
			{
				return Bin_Find(bt->Left, X);
			}
			else if (X > bt->Data)	//大于
			{
				return Bin_Find(bt->Right, X);
			}
			else	//等于
			{
				return bt;
			}
		}

		BinTree Bin_Find_Normal(BinTree bt, const T X)		//递归-顺序搜索树
		{
			if (!bt)
				return nullptr;

			if (X != bt->Data)								//前序遍历所有节点
			{
				Bin_Find(bt->Left, X);
				Bin_Find(bt->Right, X);
				return nullptr;
			}
			else	//等于
			{
				return bt;
			}
		}

		BinTree Bin_Find_new(BinTree bt, const T X)		//while
		{
			while (bt)
			{
				if (X < bt->Data)		//小于
				{
					bt = bt->Left;
				}
				else if (X > bt->Data)	//大于
				{
					bt = bt->Right, X;
				}
				else
				{
					return bt;
				}
			}
			return nullptr;
		}

		BinTree Bin_FindMin(BinTree bt)
		{
			if (!bt)
				return nullptr;

			while (bt->Left)
			{
				bt = bt->Left;
			}

			return bt;
		}

		BinTree Bin_FindMax(BinTree bt)
		{
			if (!bt)
				return nullptr;

			while (bt->Right)
			{
				bt = bt->Right;
			}

			return bt;
		}

		BinTree Bin_Insert(BinTree bt, const ElementType x)
		{
			if (bt == nullptr)
			{
				bt = make_shared<TreeNode>();
				bt->Left = nullptr;
				bt->Right = nullptr;
				bt->Data = x;
			}
			else
			{
				if (x < bt->Data)
				{
					bt->Left = Bin_Insert(bt->Left, x);
				}
				else if (x > bt->Data)
				{
					bt->Right = Bin_Insert(bt->Right, x);
				}
			}
			return bt;
		}

		BinTree Bin_Delete_right(BinTree bt, const ElementType x)
		{
			if (bt == nullptr)
			{
				return nullptr;
			}
			else if (x < bt->Data)
			{
				bt->Left = Bin_Delete_right(bt->Left, x);
			}
			else if (x > bt->Data)
			{
				bt->Right = Bin_Insert(bt->Right, x);
			}
			else if (bt->Left && bt->Right)	//找到了data为x的节点，但是左右都有孩子
			{
				//在右子树中找最小值
				BinTree tmp = Bin_FindMin(bt->Right);
				bt->Data = tmp->Data;
				bt->Right = Bin_Delete_right(bt->Right, bt->Data);
			}
			else
			{
				if (bt->Left)	//有左
				{
					bt = bt->Left;
				}
				else if (bt->Right)	//有右
				{
					bt = bt->Right;
				}
				else  //左右都没有
				{
					bt = nullptr;	//只有使用智能指针的时候才能这样给nullptr，不然需要free
				}
			}
			return bt;
		}

		BinTree Bin_Delete_left(BinTree bt, const ElementType x)
		{
			if (bt == nullptr)
			{
				return nullptr;
			}
			else if (x < bt->Data)
			{
				bt->Left = Bin_Delete_left(bt->Left, x);
			}
			else if (x > bt->Data)
			{
				bt->Right = Bin_Delete_left(bt->Right, x);
			}
			else if (bt->Left && bt->Right)	//找到了data为x的节点，但是左右都有孩子
			{
				//左子树中找最大值
				BinTree tmp = Bin_FindMax(bt->Left);
				bt->Data = tmp->Data;
				bt->Left = Bin_Delete_left(bt->Left, bt->Data);
			}
			else
			{
				if (bt->Left)	//有左
				{
					bt = bt->Left;
				}
				else if (bt->Right)	//有右
				{
					bt = bt->Right;
				}
				else  //左右都没有
				{
					bt = nullptr;	//只有使用智能指针的时候才能这样给nullptr，不然需要free
				}
			}
			return bt;
		}
	};

	void main_4_1();
}




#endif
