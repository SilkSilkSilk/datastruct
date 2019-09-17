#include "6.5.1.h"


namespace Main_6_5_1
{	//¡¥±Ì µœ÷Õº


	void main_6_5_1()
	{
		class_6_5_1<int> a(10);

		a.InsertEdge(a.CreatEdge(1, 2, 10));
		a.InsertEdge(a.CreatEdge(1, 4, 10));
		a.print();
	}

}
