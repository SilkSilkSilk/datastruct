#ifndef __MAIN_2_3_2_H__
#define __MAIN_2_3_2_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>


namespace Main_2_3_2
{	//链表实现循环队列
	using namespace std;


	template<class T> class class_2_3_2
	{
	public:
		#define ERROR -1010

		typedef T ElementType;

		struct Node
		{
			T Data;
			shared_ptr<Node> Next;
		};

		typedef shared_ptr<Node> Queue;					//智能指针管理内存

		Queue Front;		//头
		Queue Rear;			//尾
		int Q_size;			//队列大小  因为链表没有上限，需要给一个最大长度
		int MAX_size;		//最大长度

		class_2_3_2(const int x) :Front(nullptr), Rear(nullptr), MAX_size(x), Q_size(-1)
		{

		}

		void AddQ(ElementType item)
		{
			if (Q_size >= MAX_size)
			{
				cout << "queue is full" << endl;
				return;
			}

			Queue p(new Node());
			p->Data = item;
			p->Next = nullptr;

			if (Rear == nullptr)			//没有首元素
			{
				Rear = Front =  p;			//front和rear要有相同的起点
			}
			else							
			{
				Rear->Next = p;
				Rear = p;
			}

			Q_size++;
		}

		ElementType DeleteQ()
		{
			if (Front == nullptr)					//队列不为空
			{
				cout << "queue is Empty!" << endl;
				return ElementType(ERROR);			//ElementType也就是T需要支持int的初始化
			}

			Queue front_tem = Front;				//保存头元素
			if (Front == Rear)						//队列中只有一个元素
			{
				Front = Rear = nullptr;
			}
			else									//很多元素
			{
				Front = Front->Next;				//使front指向链表第二个节点
			}
			Q_size--;
			
			return front_tem->Data;
		}											//不需要手动释放链表第一节点的内存，智能指针自动释放

		int isFullQ()
		{
			return Q_size == MAX_size ? 1 : 0;
		}

		int isEmptyQ()
		{
			if (Front == nullptr)					//队列为空
			{
				return 1;
			}
			return 0;
		}

		~class_2_3_2()
		{
			//析构
		}
	};

	void main_2_3_2();

}

#endif
