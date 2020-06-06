#ifndef __MAIN_9_1_H__
#define __MAIN_9_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>

namespace Main_9_1
{	//≈≈–Ú
	using namespace std;

	template <class T>
	void swap(T& a, T& b) noexcept
	{
		a = a - b;
		b = a + b;
		a = b - a;
	}

	template <class T>
	void print(T array[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	void main_9_1();
}

#endif
