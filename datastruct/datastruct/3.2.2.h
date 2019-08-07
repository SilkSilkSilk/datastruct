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
		BinTree BinTree_Creat(const vector<T>& s)
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

		//先序和中序创建二叉树
		BinTree BinTree_Creat(vector<T> &s1, vector<T> &s2)
		{
			if (s1.empty() || s2.empty())
			{
				return nullptr;
			}

			BinTree bt;
			vector<T> s1_l, s1_r;
			vector<T> s2_l, s2_r;

			vector<T>::iterator it = find(s2.begin(), s2.end(), s1[0]);	//在中序数组中找左右子树
			if (it != s2.end())	//找不到应该是错误
			{
				s2_l.insert(s2_l.begin(), s2.begin(), it);		//左子树
				s2_r.insert(s2_r.begin(), it + 1, s2.end());		//右子树
			}

			if (!s2_l.empty())	//左子树不为空
			{
				s1_l.insert(s1_l.begin(), s1.begin() + 1, s1.begin() + 1 + s2_l.size());		//左子树
				s1_r.insert(s1_r.begin(), s1.begin() + 1 + s2_l.size(), s1.end());			//右子树
			}
			else
			{
				s1_r.insert(s1_r.begin(), s1.begin() + 1, s1.end());			//右子树
			}
			
			
			bt = make_shared<TreeNode>();
			bt->Data = s1[0];
			bt->Left = BinTree_Creat(s1_l, s2_l);
			bt->Right = BinTree_Creat(s1_r, s2_r);

			return bt;
		}

		//后序和中序创建二叉树---优化vector的重复拷贝
		BinTree BinTree_Creat_end(vector<T> &s1, vector<T> &s2, int s1_l , int s1_r, int s2_l, int s2_r)
		{
			if (s1_l > s1_r || s2_l > s2_r)
			{
				return nullptr;
			}

			int i = s2_l;
			for (; i <= s2_r; i++)
			{
				if (s2[i] == s1[s1_r])
				{
					break;
				}
			}

			BinTree bt;
			bt = make_shared<TreeNode>();
			bt->Data = s1[s1_r];

//			(s2_r - i)
			bt->Left = BinTree_Creat_end(s1, s2, s1_l, s1_r - (s2_r - i) - 1, s2_l, i - 1);
			bt->Right = BinTree_Creat_end(s1, s2, s1_r - (s2_r - i), s1_r - 1, i + 1, s2_r);

			return bt;
		}

		class_3_2_2(const vector<T> &s, const int max_size = 1024) : BinTree_size(-1)	//先序创建二叉树
		{
			BinTree_Maxsize = max_size;
			local_tree = BinTree_Creat(s);  //最后返回根
		}

		class_3_2_2(vector<T> &s1, vector<T> &s2, const int a, const int max_size = 1024) : BinTree_size(-1)	//先序(后序)和中序创建二叉树
		{
			if (a == 0 || a == 1)
			{
				if (a == 0)			//先序和中序
				{
					BinTree_Maxsize = max_size;
					local_tree = BinTree_Creat(s1, s2);  //最后返回根
				}
				else				//后序和中序
				{
					BinTree_Maxsize = max_size;
					local_tree = BinTree_Creat_end(s1, s2, 0, s1.size() - 1, 0, s2.size() - 1);  //最后返回根
//					local_tree = BinTree_Creat_end(s1, s2);  //最后返回根
				}
			}
			else
			{
				cout << "error: paramaeter 'a' not ture data" << endl;
			}
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
			cout << endl;
		}

		void InOrderTraversal(BinTree bt)		//递归中序
		{
			if (bt != nullptr)
			{
				InOrderTraversal(bt->Left);
				cout << bt->Data << ' ';
				InOrderTraversal(bt->Right);
			}
			cout << endl;
		}

		void PostOrderTraversal(BinTree bt)		//递归后序
		{
			if (bt != nullptr)
			{
				PostOrderTraversal(bt->Left);
				PostOrderTraversal(bt->Right);
				cout << bt->Data << ' ';
			}
			cout << endl;
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
			cout << endl;
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
			cout << endl;
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
			cout << endl;
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
			cout << endl;
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
		
		bool Is_morphic(BinTree bt1, BinTree bt2)		//判断树是否是同构 true为同构
		{
			if (bt1 == nullptr && bt2 == nullptr)		//都为空 
			{
				return true;
			}

			if ((bt1 == nullptr && bt2 != nullptr) || (bt1 != nullptr && bt2 == nullptr))		//一个为空另一个不为空
			{
				return false;
			}

			if (bt1->Data != bt2->Data)		//根节点的值不一样 
			{
				return false;
			}

			bool flag1, flag2;

			if (Is_morphic(bt1->Left, bt2->Left) == false)
			{
				flag1 = Is_morphic(bt1->Left, bt2->Right);
			}
			else
			{
				flag1 = true;
			}

			if (Is_morphic(bt1->Right, bt2->Right) == false)
			{
				flag2 = Is_morphic(bt1->Right, bt2->Left);
			}
			else
			{
				flag2 = true;
			}

			return (flag1 && flag2);
		}

		//判断两棵树是否同构  
		int Isomorphic(BinTree t1, BinTree t2) 
		{
			if ((t1 == NULL) && (t2 == NULL))return 1;		//都为空 
			
			if (((t1 == NULL) && (t2 != NULL)) || ((t1 != NULL) && (t2 == NULL))) return 0;		//一个为空另一个不为空 
			
			if (t1->Data != t2->Data) return 0;		//根节点的值不一样  

			if ((t1->Left == NULL) && (t2->Left == NULL)) return Isomorphic(t1->Left, t2->Right);

			if (((t1->Left != NULL) && (t2->Left != NULL)) && (t1->Left->Data == t2->Left->Data))		//没有交换  
				return (Isomorphic(t1->Left, t2->Left) && Isomorphic(t1->Right, t2->Right));		//如果两个都不为空且左儿子相等，应该递归的找左对应左，右对应右  
			else
				return (Isomorphic(t1->Left, t2->Right) && Isomorphic(t1->Right, t2->Left));		//否则就是交换了，递归的判断左对应右，右对应左  
		};

	};

	

	void main_3_2_2();
	void main_3_2_2_new();
	void main_3_2_2_morphic();
	void main_3_2_2_morphic_new();
}

#endif
