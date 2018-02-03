#include <iostream>
#include <vector>

#include "2.4.h"
#include "2.2.h"
#include "2.6.h"
#include "2.7.h"


using namespace std;

shared_ptr<int> pt = make_shared<int>(10);

void aa()
{
	int *p;

	p = &*pt;			//将智能指针的对象地址赋给普通指针不会使计数器增加   如果智能指针在普通指针之前销毁，那么普通指针不可用

	cout << pt.use_count() << endl;
}

int main()
{
//	Main_2_2::main_2_2();
//	Main_2_4::main_2_4();
//	Main_2_6::main_2_6();

//	Main_2_7::main_2_7();

	aa();
	cout << pt.use_count() <<endl;

	return 0;
}
