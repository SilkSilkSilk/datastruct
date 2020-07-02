#include "10.1.h"

namespace Main_10_1
{
	template <class T>
	void print(T array[], int n)
	{
		if (array == nullptr)
			return;
		for (int i = 0; i < n; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void main_10_1()
	{
		#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

		vector<int> a;
		/*hash_map<int, int> hashmap;
		hashmap[0] = 10;
		hashmap[20] = 20;
		hashmap[17] = 17;
		hashmap[6] = 6;
		hashmap[3] = 3;
		hashmap[100] = 100;
		hashmap[11] = 11;
		for(auto item : hashmap)
		{
			cout << item.second << " ";
		}
		cout << endl;*/

		my_map_int<int> intmap(pair<int, int>(1 << 31, 1 << 31), pair<int, int>(1 << 30, 1 << 30));

		intmap.insert(0, 10);
		intmap.insert(20, 20);
		intmap.insert(17, 17);
		intmap.insert(6, 6);
		intmap.insert(3, 3);
		intmap[100] = 100;
		intmap[11] = 11;

		for (auto &item : intmap)
		{
			if (item != pair<int, int>(1 << 31, 1 << 31) && item != pair<int, int>(1 << 30, 1 << 30))
				cout << "(" << item.first << ", " << item.second << ")" << endl;
		}
		cout << endl;

		intmap.insert(0, 0);
		for (auto &item : intmap)
		{
			if (item != pair<int, int>(1 << 31, 1 << 31) && item != pair<int, int>(1 << 30, 1 << 30))
				cout << "(" << item.first << ", " << item.second << ")" << endl;
		}
		cout << endl;

		intmap.remove(0);
		intmap.remove(3);
		intmap.remove(0);

		for (auto &item : intmap)
		{
			if (item != pair<int, int>(1 << 31, 1 << 31) && item != pair<int, int>(1 << 30, 1 << 30))
				cout << "(" << item.first << ", " << item.second << ")" << endl;
		}
		cout << endl;
	}
}

