#include "2.7.h"


namespace Main_2_7
{//����������û��ȥʵ�֣���Ϊ�о�̫������������׼�������ѧУ�ؼ�
	MList Make_init(const vector<vector<int>> &list)
	{
		int m = list.size(), n = list[0].size();

		cout << m << " " << n << endl;

		return MList();
	}


	int main_2_7()		//��������ľ���ʵ������
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
