#include "2.2.3.h"


namespace Main_2_2_3
{
	void main_2_2_3()
	{
		class_2_2_3<int> p;			//模板类管理堆栈，堆栈使用链表来实现
									//模板类使得class_2_2_3更像vector等标准容器的操作--一个模板类对象管理一个堆栈
		auto a = p.MakeEmpty();
		
		p.Push(a, 1);				//入栈
		p.Push(a, 11);
		p.Push(a, 111);

		cout << p.Pop(a) << endl;	//出栈
		cout << p.Pop(a) << endl;
		cout << p.Pop(a) << endl;
		cout << p.Pop(a) << endl;	//没有数据时检测错误
	}
}
