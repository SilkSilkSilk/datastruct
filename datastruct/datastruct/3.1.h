#ifndef __MAIN_3_1_H__
#define __MAIN_3_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include<ctime>


namespace Main_3_1
{	//顺序查找和二分查找
	using namespace std;


	template<class T> class class_3_1
	{
	public:
		#define ERROR -1010
		typedef T ElementType;

		struct List
		{
			shared_ptr<T[]> Data;							//shared_ptr<T[]>表示Data是指向数组类型的
			int len;		//长度
		};

		typedef shared_ptr<List> SList;					//智能指针管理内存
		SList local_queue;
		int Maxsize;

		class_3_1(const int max_size = 1024)	//构造	初始化队列认	默认长度为1024
		{
			local_queue = make_shared<List>();			//初始化智能指针
			local_queue->len = max_size;

			shared_ptr<T[]> tem(new T[max_size]());		//表示tem是指向数组类型的智能指针
			local_queue->Data = tem;
			Maxsize = max_size;
		}

		~class_3_1()
		{
			//析构
		}

		int Seque_search(SList s, T k)						//时间复杂度On
		{
			if (s == nullptr)
			{
				return 0;		//表示失败
			}
			
			s->Data[0] = k;
			int i;

			for ( i = s->len; s->Data[i] != k; i--);		//i的位置是k数据位置或0  0表示找不到 
		
			return i;
		}

		void srand_SList(SList s)				//初始化SList
		{
			for (int i = 0; i < s->len; i++)
			{
				s->Data[i] = (i + 1) * 5;
//				cout << s->Data[i] << " ";
			}
		
		}

		int Binary_search(SList s, T k)						//时间复杂度〖log〗_2 n
		{
			int left, right, mid;

			left = 1;			//有效数据从1开始
			right = s->len;

			while (left <= right)
			{
				mid = (left + right) / 2;

				if (s->Data[mid] > k)
				{
					right = mid - 1;
				}
				else if(s->Data[mid] < k)
				{
					left = mid + 1;
				}
				else
				{
					return mid;
				}
			}
			return -1;
		}


	};

	void main_3_1();

}

#endif
