#ifndef __MAIN_2_2_4_2_H__
#define __MAIN_2_2_4_2_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "2.2.3.h"


namespace Main_2_2_4_2
{	//使用中缀表达式堆栈的编程方法实现了表达式计算
	using namespace std;

	class Mytype
	{
	public:
		float value;		//存储数据
		int tag;			//区分数据项和运算符  0=数据 1=运算符
		string type;		//运算符
		int priority;		//优先级

		Mytype();
		Mytype(int e);
		Mytype(float f);
		~Mytype();

		void make_Mytype_data(float va);
		void make_Mytype_type(string ty);

		float print();
	};

	//	extern vector<Mytype> Vm;

	void Calculate(Main_2_2_3::class_2_2_3<Mytype> &stack_data, Mytype s);

	int brackets_expression(vector<Mytype> &s);

	void main_2_2_4_2();
}

#endif
