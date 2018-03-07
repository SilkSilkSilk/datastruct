#include "2.3.2.h"

namespace Main_2_3_2
{	//链表实现队列

	void main_2_3_2()
	{
		class_2_3_2<int> a(100);

		a.AddQ(1);
		a.AddQ(2);
		a.AddQ(3);

		cout << a.DeleteQ() << endl;
		cout << a.DeleteQ() << endl;
		cout << a.DeleteQ() << endl;
		cout << a.DeleteQ() << endl;
		//队列是先进先出，所以得到1 2 3和 error；
	}

}
