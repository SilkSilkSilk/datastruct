#include "4.1.h"

namespace Main_4_1
{
	void main_4_1()
	{
		cout << "������������򴴽�������a1" << endl;
		vector<int> s1 = { 8, 3, 1, 6, 4, 7, 10, 14, 13 };
		vector<int> s2 = { 1, 3, 4, 6, 7, 8, 10, 13, 14 };
		class_4_1<int> a1(s1, s2, 0, 100); //����������

		cout << "��֤a1 ��ջ����" << endl;
		a1.InOrderTraversal_stack(a1.local_tree);

		cout << endl << "a1��Ѱ��8������ݣ�����Ԫ�ص�ָ��--�ݹ�, ";
		cout << "�����Ƿ���ȷ��" << (a1.Bin_Find(a1.local_tree, 8)->Data == 8 ? "��ȷ":"����") << endl;

		cout << endl << "a1��Ѱ��8������ݣ�����Ԫ�ص�ָ��--while, ";
		cout << "�����Ƿ���ȷ��" << (a1.Bin_Find_new(a1.local_tree, 8)->Data == 8 ? "��ȷ" : "����") << endl;

		cout << endl << "a1��Ѱ����Сֵ:";
		cout << a1.Bin_FindMin(a1.local_tree)->Data << endl;

		cout << "a1��Ѱ�����ֵ:";
		cout << a1.Bin_FindMax(a1.local_tree)->Data << endl;
		
	}
}
