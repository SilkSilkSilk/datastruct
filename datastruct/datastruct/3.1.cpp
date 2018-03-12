#include "3.1.h"

namespace Main_3_1
{	//数组实现循环队列

	void main_3_1()
	{
		class_3_1<int> a(100);								//顺序查找

		a.local_queue->Data[34] = 18;

		auto an = a.Seque_search(a.local_queue, 18);		

		cout << "Subscript " << an << " is ";
		cout << a.local_queue->Data[an] << endl;



		class_3_1<int> b(18);								//二分查找

		b.srand_SList(b.local_queue);

		auto bn = b.Binary_search(b.local_queue, 55);

		cout << "Subscript " << bn << " is ";
		cout << b.local_queue->Data[bn] << endl;
	}

}
