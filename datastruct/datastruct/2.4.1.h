#ifndef __MAIN_2_4_1_H__
#define __MAIN_2_4_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "2.3.2.h"


namespace Main_2_4_1
{
	//继承队列模板类，实现多项式存储和+运算
	using namespace std;
	using namespace Main_2_3_2;


	struct PolyNode					//表示多项式数据类型
	{
		PolyNode() :coef(0), expon(0)	//默认构造
		{

		}

		PolyNode(int n)				//为了将ERROR转换成T类型
			: expon(0)
		{
			coef = n;
		}

		PolyNode(int a, int b)		//快速构造多项式单元
			: coef(a), expon(b)
		{
			
		}


		int coef; //系数
		int expon; //指数
	};


	template <class T = PolyNode> class class_2_4_1 : public class_2_3_2<T>		//继承队列模板类，实现多项式存储和+运算
	{
	public:
		class_2_4_1(const int x = 100)
			: class_2_3_2(x) //调用积累构造函数  x表示队列最大长度限制
		{
		}


		T Qreturn() //返回首元素而不删除
		{
			if (Front == nullptr) //队列不为空
			{
				cout << "queue is Empty!" << endl;
				return T(ERROR); //T需要支持int的初始化
			}

			return Front->Data;
		}


		int Qcompare(T a, T b)			//比较系数大小
		{
			if (a.expon > b.expon) //大于
			{
				return 1;
			}
			if (a.expon < b.expon) //小于
			{
				return -1;
			}
			//相同
			return 0;
		}

		void Attach(T &a, class_2_4_1<T> &b)		//将一个多项式节点加入队列中
		{
			b.AddQ(a);
		}


		class_2_4_1<T> operator+(class_2_4_1<T>& s)	//实现多项式加法运算，而却还能连续+  a+b+c
		{
			class_2_4_1<T> temp;

			while (!this->isEmptyQ() && !s.isEmptyQ())
			{
				switch (Qcompare(this->Qreturn(), s.Qreturn()))
				{
					case 1:
						Attach(this->DeleteQ(), temp);
						break;

					case -1:
						Attach(s.DeleteQ(), temp);
						break;

					case 0:
						auto a = this->DeleteQ();
						auto b = s.DeleteQ();

						a.coef = a.coef + b.coef;
						if (a.coef)					//大于0放入temp
						{
							Attach(a, temp);
						}
						break;
				}
			}

			while (!this->isEmptyQ())
			{
				Attach(this->DeleteQ(), temp);
			}

			while (!s.isEmptyQ())
			{
				Attach(s.DeleteQ(), temp);
			}

			return temp;
		}


		void print();
	};


	void main_2_4_1();
}

#endif
