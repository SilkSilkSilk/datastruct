#include "2.2.4.2.h"


namespace Main_2_2_4_2
{
	Mytype::Mytype() :
		value(),
		tag(),
		type(),
		priority()
	{

	}

	Mytype::Mytype(int e):
		value(static_cast<float>(e)),
		tag(0),
		type(),
		priority()
	{
	}

	Mytype::Mytype(float f):
		value(f),
		tag(0),
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
			priority = 0;
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
			priority = -1;		//error
		}
	}

	float Mytype::print()
	{
		return value;
	}

	void Calculate(Main_2_2_3::class_2_2_3<Mytype> &stack_data, Mytype s)
	{
		if (s.type == "+")
		{
			float a = stack_data.Pop().value;
			float b = stack_data.Pop().value;

			cout << a << " " << s.type << " " << b << endl;

			stack_data.Push(a + b);
		}
		else if (s.type == "-")
		{
			float a = stack_data.Pop().value;
			float b = stack_data.Pop().value;

			cout << a << " " << s.type << " " << b << endl;

			stack_data.Push(a - b);
		}
		else if (s.type == "*")
		{
			float a = stack_data.Pop().value;
			float b = stack_data.Pop().value;

			cout << a << " " << s.type << " " << b << endl;

			stack_data.Push(a * b);
		}
		else if (s.type == "/")
		{
			float a = stack_data.Pop().value;
			float b = stack_data.Pop().value;

			cout << a << " " << s.type << " " << b << endl;

			stack_data.Push(a / b);
		}
	}

	int brackets_expression(vector<Mytype> &s)
	{
		if (s.size() == 0)		//空
		{
			return ERROR;
		}

		Main_2_2_3::class_2_2_3<Mytype> stack_data;
		stack_data.MakeEmpty();
		Main_2_2_3::class_2_2_3<Mytype> stack_type;
		stack_type.MakeEmpty();

		for (auto i : s)
		{
			if (i.tag == 0)	//数据
			{
				stack_data.Push(i);
			}
			else	//操作符
			{
				if (i.type == "+" || i.type == "-" || i.type == "*" || i.type == "/")
				{
					if (stack_type.IsEmpty() == 1)			//空栈判断
					{
						stack_type.Push(i);
					}
					else
					{
						int this_pri = i.priority;
						auto temp = stack_type.Top();		//一定不会为空栈
						int last_pri = temp.priority;

						if (this_pri > last_pri)			//上一次的运算符优先级比这次大
						{
							stack_type.Push(i);
						}
						else
						{
							while (this_pri <= last_pri)	//(2+3*5-  -<* -<=+ - !< (
							{
								Calculate(stack_data, stack_type.Pop());

								if (stack_type.IsEmpty() != 1)	//堆栈中还有操作符
								{
									temp = stack_type.Top();
									last_pri = temp.priority;
								}
								else					//3*5-  堆栈中没有操作符了
								{
									break;
								}
							}

							stack_type.Push(i);			//当2+3*5运算完后将-入栈
						}
					}
				}
				else if (i.type == "(")
				{
					stack_type.Push(i);
				}
				else if (i.type == ")")
				{
					while (stack_type.Top().type != "(")
					{
						Calculate(stack_data, stack_type.Pop());
					}
					stack_type.Pop();		//去除(
				}
			}
		}

		while (stack_type.IsEmpty() != 1)
		{
			Calculate(stack_data, stack_type.Pop());
		}

		return static_cast<int>(stack_data.Top().value);
	}

	void main_2_2_4_2()
	{
		string a("(3+2)*(5+2)");

		vector<Mytype> Vm;

		for (auto i : a)				//解析字符串
		{
			Mytype p;

			if (i >= 48 && i <= 57)		//判断字符是数字还是符号
			{
				p.make_Mytype_data(i - 48);
			}
			else						//还应该检测()和运算符，过滤掉错误字符
			{
				p.make_Mytype_type(string(1, i));	//i是char类型,初始化1个char字符
			}

			Vm.push_back(p);
		}

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
		cout << endl;

		cout << brackets_expression(Vm) << endl;
	}

}
