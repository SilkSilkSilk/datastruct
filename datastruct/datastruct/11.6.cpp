#include "11.6.h"

namespace Main_11_6
{

	void main_11_6()
	{
		HBTree<int> b_tree;
		b_tree.insert(10);
		b_tree.insert(13);
		b_tree.insert(18);
		b_tree.insert(8);
		b_tree.insert(20);
		b_tree.insert(16);
		b_tree.insert(29);
		b_tree.insert(58);
		b_tree.insert(6);
		b_tree.insert(1);
		b_tree.insert(3);
		b_tree.insert(49);

		while(1)
		{
			int num = 0;
			cout << "enter num for search:" << endl;
			cin >> num;
			auto ret = b_tree.search(num);
			cout << "search result: " << ret.first << endl;
		}
	}

}