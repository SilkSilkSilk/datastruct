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

	p = &*pt;			//������ָ��Ķ����ַ������ָͨ�벻��ʹ����������   �������ָ������ָͨ��֮ǰ���٣���ô��ָͨ�벻����

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
