#include "9.1.h"

namespace Main_9_1
{
	template <class T>
	void bubble_sort(T array[], int n)
	{
		int temp;
		for (int i = 0; i < n; i++)
		{
			bool flag = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(array[j], array[j + 1]);
					flag = true;
				}
			}
			if (flag)
				break;
		}
	}

	template <class T>
	void insert_sort(T array[], int n)
	{
		int temp;
		int j;
		for (int i = 1; i < n; i++)
		{
			temp = array[i];
			for (j = i - 1; j >= 0 && temp < array[j]; j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = temp;
		}
	}

	template <class T>
	void select_sort(T array[], int n)
	{
		int j;
		for (int i = 0; i < n; i++)
		{
			int min = i;
			for (j = i + 1; j < n; j++)
			{
				if (array[j] < array[min])
				{
					min = j;
				}
			}
			if (min != i)
				swap(array[i], array[min]);
		}
	}

	void main_9_1()
	{
		std::vector<int> array = {4, 9, 10, 1, 7, 8, 2};

		//bubble_sort(&array[0], array.size());	//√∞≈›≈≈–Ú
		//insert_sort(&array[0], array.size()); //≤Â»Î≈≈–Ú
		select_sort(&array[0], array.size()); //—°‘Ò≈≈–Ú
		print(&array[0], array.size());
	}
}
