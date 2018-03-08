#include "2.5.h"


namespace Main_2_5
{
	void main_2_5()
	{
		class_2_5<> a(10);				//使用默认类型
		class_2_5<> b(10);
		class_2_5<> c(10);

		a.AddQ(PolyNode(3, 4));				//队列加入多项式数据	3表示系数 5表示次方
		a.AddQ(PolyNode(-5, 2));
		a.AddQ(PolyNode(6, 1));
		a.AddQ(PolyNode(-2, 0));

		b.AddQ(PolyNode(5, 20));
		b.AddQ(PolyNode(-7, 4));
		b.AddQ(PolyNode(3, 1));

		c.AddQ(PolyNode(1, 4));
		c.AddQ(PolyNode(1, 3));
		c.AddQ(PolyNode(1, 2));
		c.AddQ(PolyNode(1, 1));

		auto num = a * b;					//operator*实现*运算

		num.print();						//打印结果
	}
}
