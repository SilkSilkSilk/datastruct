#include "2.2.3.h"


namespace Main_2_2_3
{
	void main_2_2_3()
	{
		class_2_2_3<int> p;			//ģ��������ջ����ջʹ��������ʵ��
									//ģ����ʹ��class_2_2_3����vector�ȱ�׼�����Ĳ���--һ��ģ����������һ����ջ
		auto a = p.MakeEmpty();
		
		p.Push(a, 1);				//��ջ
		p.Push(a, 11);
		p.Push(a, 111);

		cout << p.Pop(a) << endl;	//��ջ
		cout << p.Pop(a) << endl;
		cout << p.Pop(a) << endl;
		cout << p.Pop(a) << endl;	//û������ʱ������
	}
}
