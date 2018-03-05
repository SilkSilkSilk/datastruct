#ifndef __MAIN_2_3_1_H__
#define __MAIN_2_3_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>


namespace Main_2_3_1
{	//数组实现循环队列
	using namespace std;


	template<class T> class class_2_3_1
	{
	public:
		#define ERROR -1010
		typedef T ElementType;

		struct QNode
		{
			shared_ptr<T[]> Data;							//shared_ptr<T[]>表示Data是指向数组类型的
			int front;		//头
			int rear;		//尾
		};

		typedef shared_ptr<QNode> Queue;					//智能指针管理内存
		Queue local_queue;
		int Maxsize;
		
		class_2_3_1(const int max_size = 1024)	//构造	初始化队列认	默认长度为1024
		{
			local_queue = make_shared<QNode>();			//初始化智能指针
			local_queue->front = local_queue->rear = -1;

			shared_ptr<T[]> tem(new T[max_size]());		//表示tem是指向数组类型的智能指针
			local_queue->Data = tem;
			Maxsize = max_size;
		}

		~class_2_3_1()
		{
			//析构
		}

		Queue CreatQueue(const int max_size = 1024)		//初始化队列	默认长度为1024
		{
			local_queue = make_shared<QNode>();			//初始化智能指针
			local_queue->front = local_queue->rear = -1;

			shared_ptr<T[]> tem(new T[max_size]());		
			local_queue->Data = tem;
			Maxsize = max_size;
		}

		int isFullQ()		
		{
			if ((local_queue->rear + 1) % Maxsize == local_queue->front)
			{
				return 1;		//queue is full
			}
			return 0;
		}

		int isEmptyQ()
		{
			if (local_queue->rear == local_queue->front)	
			{
				return 1;		//queue is Empty
			}
			return 0;
		}

		void AddQ(ElementType item)
		{
			if ((local_queue->rear + 1) % Maxsize == local_queue->front)	//循环队列使用了maxsize-1个空间,避免了front=rear的情况
			{
				cout << "queue is full!" << endl;
				return;
			}

			local_queue->rear = (local_queue->rear + 1) % Maxsize;
			local_queue->Data[local_queue->rear] = item;
		}

		ElementType DeleteQ()
		{
			if (local_queue->rear == local_queue->front)
			{
				cout << "queue is Empty!" << endl;
				return ElementType(ERROR);			//ElementType也就是T需要支持int的初始化
			}
			else
			{
				local_queue->front = (local_queue->front + 1) % Maxsize;
				return local_queue->Data[local_queue->front];
			}
		}
	};

	void main_2_3_1();

}

#endif
