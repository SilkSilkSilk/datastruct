#include "2.4.1.h"


namespace Main_2_4_1
{
	void main_2_4_1()
	{
		class_2_4_1<> a(10);				//使用默认类型
		class_2_4_1<> b(10);
		class_2_4_1<> c(10);

		a.AddQ(PolyNode(3, 5));				//队列加入多项式数据	3表示系数 5表示次方
		a.AddQ(PolyNode(4, 4));
		a.AddQ(PolyNode(-1, 3));
		a.AddQ(PolyNode(2, 1));
		a.AddQ(PolyNode(-1, 0));

		b.AddQ(PolyNode(2, 4));
		b.AddQ(PolyNode(1, 3));
		b.AddQ(PolyNode(-7, 2));
		b.AddQ(PolyNode(1, 1));

		c.AddQ(PolyNode(1, 4));
		c.AddQ(PolyNode(1, 3));
		c.AddQ(PolyNode(1, 2));
		c.AddQ(PolyNode(1, 1));

		auto num = a + b + c;				//operator+实现连续+运算

		num.print();						//打印结果
	}

	template<class T>
	inline void class_2_4_1<T>::print()		//打印结果
	{
		if (this->isEmptyQ())
		{
			return;
		}

		auto a = this->DeleteQ();
		cout << a.coef << "x" << a.expon << " ";

		while (!this->isEmptyQ())
		{
			a = this->DeleteQ();
			cout <<  (a.coef >= 0 ? "+ " : "- ")  << abs(a.coef) << "x" << abs(a.expon) << " ";
		}
		cout << endl;
	}
}
