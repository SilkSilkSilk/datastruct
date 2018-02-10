#ifndef __MAIN_2_2_4_H__
#define __MAIN_2_2_4_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "2.2.3.h"


namespace Main_2_2_4
{
	using namespace std;

	class Mytype
	{
	public:
		float value;		//存储数据
		int tag;			//区分数据项和运算符  0=数据 1=运算符
		string type;		//运算符
		int priority;		//优先级

		Mytype();
		~Mytype();

		void make_Mytype_data(float va);
		void make_Mytype_type(string ty);

		float print();
	};

//	extern vector<Mytype> Vm;

	void ordinary_expression(vector<Mytype> s);
	void brackets_expression(vector<Mytype> s);

	void main_2_2_4();
}

#endif
