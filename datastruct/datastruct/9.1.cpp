#include "9.1.h"

namespace Main_9_1
{
	void main_9_1()
	{
		vector<int> array = { 3, 1, 2, 5, 8, 4 };
		//vector<int> array = {5, 1, 1, 2, 0, 0};

		//improved_insert_sort<int>(&array[0], array.size());		//选择排序
		//select_sort<int>(&array[0], array.size()); //shell排序 (增量除2递减)
		//heap_sort(&array[0], array.size());		//最小堆的库实现排序
		//heap_sort_my(&array[0], array.size()); //最小堆实现排序
		//merge_sort_recursion(&array[0], array.size()); //归并实现排序
		//bucket_sort_self(&array[0], array.size()); //桶排序-自我
		//shell_binary_sort_self(&array[0], array.size()); //2分查找+shell排序
		//bucket_sort(&array[0], array.size(), 9); //桶排序
		//radix_sort(&array[0], array.size(), 1, 10); //基数桶排序
		//quick_sort(&array[0], array.size()); //快速排序
		quick_shell_sort(&array[0], array.size()); //快速+shell 32排序
		print<int>(&array[0], array.size());
	}

}
