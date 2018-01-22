#include "2.7.h"


namespace Main_2_7
{//多重链表还是没有去实现，因为感觉太过繁琐，还有准备明天从学校回家
	MList Make_init(const vector<vector<int>> &list)
	{
		int m = list.size(), n = list[0].size();

		cout << m << " " << n << endl;

		return MList();
	}


	int main_2_7()		//多重链表的矩阵实例运用
	{
		const vector<vector<int>> a = {
			{18, 0, 0, 2, 0},
			{0, 27, 0, 0, 0},
			{0, 0, 0, -4, 0},
			{23, -1, 0, 0, 12}
		};

		Make_init(a);

		return 0;
	}
}
