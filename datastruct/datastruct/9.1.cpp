#include "9.1.h"

namespace Main_9_1
{
	void main_9_1()
	{
		vector<int> array = { 3, 1, 2, 5, 8, 4 };
		//vector<int> array = {5, 1, 1, 2, 0, 0};

		//improved_insert_sort<int>(&array[0], array.size());		//ѡ������
		//select_sort<int>(&array[0], array.size()); //shell���� (������2�ݼ�)
		//heap_sort(&array[0], array.size());		//��С�ѵĿ�ʵ������
		//heap_sort_my(&array[0], array.size()); //��С��ʵ������
		//merge_sort_recursion(&array[0], array.size()); //�鲢ʵ������
		//bucket_sort_self(&array[0], array.size()); //Ͱ����-����
		//shell_binary_sort_self(&array[0], array.size()); //2�ֲ���+shell����
		//bucket_sort(&array[0], array.size(), 9); //Ͱ����
		//radix_sort(&array[0], array.size(), 1, 10); //����Ͱ����
		//quick_sort(&array[0], array.size()); //��������
		quick_shell_sort(&array[0], array.size()); //����+shell 32����
		print<int>(&array[0], array.size());
	}

}
