#include "2.2.4.h"


namespace Main_2_2_4
{
	Mytype::Mytype():
	value(),
	tag(),
	type(),
	priority()
	{

	}

	Mytype::~Mytype()
	{

	}

	void Mytype::make_Mytype_data(float va)
	{
		value = va;
		tag = 0;
	}

	void Mytype::make_Mytype_type(string ty)
	{
		type = ty;
		tag = 1;

		if (ty == string("(") || ty == string(")"))
		{
			priority = 3;
		}
		else if (ty == string("*") || ty == string("/"))
		{
			priority = 2;
		}
		else if (ty == string("+") || ty == string("-"))
		{
			priority = 1;
		}
		else
		{
			priority = 0;		//error
		}
	}

	float Mytype::print()
	{
		return value;
	}

	void ordinary_expression(vector<Mytype> s)		//没有括号的表达式计算
	{
		int num = s.size();

		Main_2_2_3::class_2_2_3<Mytype> op_data;	//数据栈
		op_data.MakeEmpty();

		Main_2_2_3::class_2_2_3<Mytype> op_type;	//运算符栈
		op_type.MakeEmpty();



	}

	void brackets_expression(vector<Mytype> s)		//有括号的表达式计算
	{

	}

	void main_2_2_4()
	{
		vector<Mytype> Vm;

		Mytype p;
		p.make_Mytype_data(3);
		Vm.push_back(p);

		Mytype p1;
		p1.make_Mytype_type(string("+"));
		Vm.push_back(p1);

		Mytype p2;
		p2.make_Mytype_data(2);
		Vm.push_back(p2);

		Mytype p3;
		p3.make_Mytype_type(string("*"));
		Vm.push_back(p3);

		Mytype p4;
		p4.make_Mytype_data(5);
		Vm.push_back(p4);

		for (auto &i : Vm)
		{
			if (i.tag == 0)
			{
				cout << i.value;
			}
			else
			{
				cout << i.type;
			}
		}

		ordinary_expression(Vm);
	}

}