#include "6.5.h"


namespace Main_6_5
{
	void main_6_5()
	{
		class_6_5<int> a(10);

		a.InsertEdge(a.CreatEdge(1, 2, 10));
		a.print();
	}
}