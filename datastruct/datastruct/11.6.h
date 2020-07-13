#ifndef __HBTREE_H__
#define __HBTREE_H__

#include <iostream>

namespace Main_11_6
{	//红黑树实现--插入修复
	
	using namespace std;

	enum hbcolor { hbcolor_red, hbcolor_black };
	template <class T>
	class hb_node
	{
	public:
		explicit hb_node(const T& v, const hbcolor colo, hb_node* father);
		hb_node(const hb_node&) = delete;
		hb_node& operator=(const hb_node&) = delete;
		~hb_node();

		hbcolor color;
		const T& value;
		hb_node* left;
		hb_node* right;
		hb_node* father;
	};

	template <class T>
	hb_node<T>::hb_node(const T& v, const hbcolor colo, hb_node* father): color(colo), value(v), left(nullptr), right(nullptr), father(father)
	{
	}

	template <class T>
	hb_node<T>::~hb_node()
	{
		if (left)
		{
			delete left;
			left = nullptr;
		}
		if (right)
		{
			delete right;
			right = nullptr;
		}
	}

	template <class T>
	class HBTree
	{
	public:
		explicit HBTree();
		HBTree(const HBTree&) = delete;
		HBTree& operator=(const HBTree&) = delete;
		~HBTree();
		void set_node_left(hb_node<T>* src, hb_node<T>* soon);
		void set_node_right(hb_node<T>* src, hb_node<T>* soon);
		bool insert(const T& value);
		pair<bool, const T&> search(const T& value) const;
		/*void remove(const T& value);
		*/

		hb_node<T>* tree;
	};

	template <class T>
	HBTree<T>::HBTree(): tree(nullptr)
	{
	}

	template <class T>
	HBTree<T>::~HBTree()
	{
		delete tree;
	}


	template <class T>
	void HBTree<T>::set_node_left(hb_node<T>* src, hb_node<T>* soon)
	{
		if (src == nullptr)
		{
			return;
		}
		src->left = soon;
		if (soon)
		{
			src->left->father = src;
		}
	}

	template <class T>
	void HBTree<T>::set_node_right(hb_node<T>* src, hb_node<T>* soon)
	{
		if (src == nullptr)
		{
			return;
		}
		src->right = soon;
		if (soon)
		{
			src->right->father = src;
		}
	}
	
	template <class T>
	bool HBTree<T>::insert(const T& value)
	{
		if (tree == nullptr)
		{
			tree = new hb_node<T>(value, hbcolor_black, nullptr);
			return true;
		}

		hb_node<T>* temp = tree;
		hb_node<T>* fath = nullptr;
		while (temp)
		{
			if (value > temp->value)
			{
				fath = temp;
				temp = temp->right;
			}
			else if (value < temp->value)
			{
				fath = temp;
				temp = temp->left;
			}
			else
			{
				return false;
			}
		}
		temp = new hb_node<T>(value, hbcolor_red, fath);	//红色结点
		if (fath->value > value)
		{
			fath->left = temp;
		}
		else
		{
			fath->right = temp;
		}
		
		hb_node<T>* cur_node = temp;
		hb_node<T>* fat_node = nullptr;
		hb_node<T>* gra_node = nullptr;
		hb_node<T>* uncle_node = nullptr;
		while(cur_node->father)
		{
			fat_node = cur_node->father;
			//双红色结点检查
			if (cur_node->color == hbcolor_red && fat_node->color == hbcolor_red)	//父子都是红色
			{
				gra_node = fat_node->father;
				if (gra_node->right == fat_node)
				{
					uncle_node = gra_node->left;
				}
				else
				{
					uncle_node = gra_node->right;
				}
				if (uncle_node != nullptr && uncle_node->color == hbcolor_red)	//uncle (叔叔) 是红色
				{
					gra_node->color = hbcolor_red;
					uncle_node->color = hbcolor_black;
					fat_node->color = hbcolor_black;
					cur_node = gra_node;
				}
				else  //4种变化
				{
					if (cur_node == fat_node->left && fat_node == gra_node->left)	//左左
					{
						if (gra_node->father)
							if (gra_node == gra_node->father->left)
								set_node_left(gra_node->father, fat_node);
							else
								set_node_right(gra_node->father, fat_node);
						else
							fat_node->father = gra_node->father;
						gra_node->father = fat_node;

						set_node_left(gra_node, fat_node->right);
						fat_node->right = gra_node;

						fat_node->color = hbcolor_black;
						gra_node->color = hbcolor_red;
						cur_node = fat_node;
					}
					else if (cur_node == fat_node->right && fat_node == gra_node->right)	//右右
					{
						if (gra_node->father)
							if (gra_node == gra_node->father->left)
								set_node_left(gra_node->father, fat_node);
							else
								set_node_right(gra_node->father, fat_node);
						else
							fat_node->father = gra_node->father;
						gra_node->father = fat_node;

						set_node_right(gra_node, fat_node->left);
						fat_node->left = gra_node;
						
						fat_node->color = hbcolor_black;
						gra_node->color = hbcolor_red;
						cur_node = fat_node;
					}
					else if (cur_node == fat_node->left && fat_node == gra_node->right)		//右左
					{
						if (gra_node->father)
							if (gra_node == gra_node->father->left)
								set_node_left(gra_node->father, cur_node);
							else
								set_node_right(gra_node->father, cur_node);
						else
							fat_node->father = gra_node->father;
						gra_node->father = cur_node;
						fat_node->father = cur_node;

						set_node_right(gra_node, cur_node->left);
						cur_node->left = gra_node;

						set_node_left(fat_node, cur_node->right);
						cur_node->right = fat_node;

						cur_node->color = hbcolor_black;
						gra_node->color = hbcolor_red;
					}
					else /*if (cur_node == fat_node->right && fat_node == gra_node->left)*/		//左右
					{
						if (gra_node->father)
							if (gra_node == gra_node->father->left)
								set_node_left(gra_node->father, cur_node);
							else
								set_node_right(gra_node->father, cur_node);
						else
							fat_node->father = gra_node->father;
						gra_node->father = cur_node;
						fat_node->father = cur_node;

						set_node_right(fat_node, cur_node->left);
						cur_node->left = fat_node;

						set_node_left(gra_node, cur_node->right);
						cur_node->right = gra_node;

						cur_node->color = hbcolor_black;
						gra_node->color = hbcolor_red;
					}
					if (cur_node->father == nullptr)
					{
						tree = cur_node;
					}
					return true;
				}
			}
			else
			{
				return true;
			}
		}
		cur_node->color = hbcolor_black;
		tree = cur_node;
		return true;
	}

	template <class T>
	pair<bool, const T&> HBTree<T>::search(const T& value) const
	{
		if (tree == nullptr)
		{
			return {false, 0};
		}

		hb_node<T>* temp = tree;
		hb_node<T>* fath = nullptr;
		while (temp)
		{
			if (value > temp->value)
			{
				temp = temp->right;
			}
			else if (value < temp->value)
			{
				temp = temp->left;
			}
			else
			{
				return {true, temp->value};
			}
		}
		return {false, 0};
	}

	void main_11_6();
}

#endif
