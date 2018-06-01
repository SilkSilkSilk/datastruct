#ifndef __MAIN_3_2_2_H__
#define __MAIN_3_2_2_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>


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
		BinTree BinTree_Creat(const vector<int>& s)
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

		void PreOrderTraversal(BinTree bt)		//递归前序
		{
			if (bt != nullptr)
			{
				cout << bt->Data << ' ';
				PreOrderTraversal(bt->Left);
				PreOrderTraversal(bt->Right);
			}
		}

		void InOrderTraversal(BinTree bt)		//递归中序
		{
			if (bt != nullptr)
			{
				InOrderTraversal(bt->Left);
				cout << bt->Data << ' ';
				InOrderTraversal(bt->Right);
			}
		}

		void PostOrderTraversal(BinTree bt)		//递归后序
		{
			if (bt != nullptr)
			{
				PostOrderTraversal(bt->Left);
				PostOrderTraversal(bt->Right);
				cout << bt->Data << ' ';
			}
		}
		 
		void PreOrderTraversal_stack(BinTree bt)		//堆栈前序
		{
			stack<BinTree> st;

			while (bt || !st.empty())
			{
				while (bt)					//查左
				{
					cout << bt->Data << ' ';
					st.push(bt);
					bt = bt->Left;
				}

				if (!st.empty())
				{
					bt = st.top();			//取数据
					st.pop();				//出栈
					//cout << bt->Data << ' ';
					bt = bt->Right;
				}
			}
		}

		void InOrderTraversal_stack(BinTree bt)		//堆栈中序
		{
			stack<BinTree> st;

			while (bt || !st.empty())
			{
				while (bt)					//查左
				{
					st.push(bt);
					bt = bt->Left;
				}

				if (!st.empty())
				{
					bt = st.top();			//取数据
					st.pop();				//出栈
					cout << bt->Data << ' ';
					bt = bt->Right;
				}
			}
		}

		void PostOrderTraversal_stack(BinTree bt)		//堆栈后序
		{
			stack<BinTree> st;
			BinTree bq = nullptr;

			while (bt || !st.empty())
			{
				while (bt)					//查左
				{
					st.push(bt);
					bt = bt->Left;
				}

				bt = st.top();			//取数据
				if (bt->Right && bt->Right != bq)
				{
					bt = bt->Right;
				}
				else
				{
					st.pop();				//出栈
					cout << bt->Data << ' ';
					bq = bt; 
					bt = nullptr;
				}
			}
		}

		void LevelOrderTraversal(BinTree bt)	//层序遍历
		{
			if (!bt) return;
			queue<BinTree> qt;

			qt.push(bt);
			while (!qt.empty())
			{
				bt = qt.front();		//返回头数据
				qt.pop();		//删除头数据
				cout << bt->Data << ' ';
				if (bt->Left)
				{
					qt.push(bt->Left);
				}
				if (bt->Right)
				{
					qt.push(bt->Right);
				}
			}
		}

		int PostOrderGetHeight(BinTree bt)
		{
			int hl, hr, maxh;
			if (bt)
			{
				hl = PostOrderGetHeight(bt->Left);
				hr = PostOrderGetHeight(bt->Right);
				maxh = (hl > hr) ? hl : hr;
				return (maxh + 1);
			}
			else
				return 0;
		}

	};

	void main_3_2_2();

}

#endif
