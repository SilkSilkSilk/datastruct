#include "5.1.h"


namespace Main_5_1
{
	void main_5_1()
	{
		class_5_1<int> a(10);
		a.Insert(1);
		a.Insert(2);
		a.Insert(3);
		a.Insert(4);
		a.Insert(5);
		a.Insert(6);
		a.Insert(7);
		a.Insert(3);
		a.print();

		bool is_success = false;
		int ret = 0;

		ret = a.DeleteMax(&is_success);
		if (is_success)
		{
			cout << "Throw the highest priority task : " << ret << endl;
		}
		a.print();

		ret = a.DeleteMax(&is_success);
		if (is_success)
		{
			cout << "Throw the highest priority task : " << ret << endl;
		}
		a.print();

		ret = a.DeleteMax(&is_success);
		if (is_success)
		{
			cout << "Throw the highest priority task : " << ret << endl;
		}
		a.print();

		ret = a.DeleteMax(&is_success);
		if (is_success)
		{
			cout << "Throw the highest priority task : " << ret << endl;
		}
		a.print();

		ret = a.DeleteMax(&is_success);
		if (is_success)
		{
			cout << "Throw the highest priority task : " << ret << endl;
		}
		a.print();
	}
}
