#include "1.h"

using namespace std;


template <class T> class Ret_max //���������
{
public:
	T a; //��������				
	int i, j; //��βλ��
};


template <class T> T MaxSubseqSum1(vector<T>& a);
template <class T> Ret_max<T> MaxSubseqSum2(vector<T>& a);


void main_1()
{
	vector<int> a{-1, 3, -2, 4, -6, 1, 6, -1};
	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << MaxSubseqSum1(a) << endl;

	Ret_max<int> ret;

	ret = MaxSubseqSum2(a);

	cout << "at " << ret.i << " - " << ret.j << " is " << ret.a << endl;
}


//nƽ��
template <class T> T MaxSubseqSum1(vector<T>& a)
{
	int ThisSum = 0, MaxSum = 0;
	int i, j, N = a.size();

	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; j < N; j++)
		{
			ThisSum += a[j];
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}


//n
template <class T> Ret_max<T> MaxSubseqSum2(vector<T>& a)
{
	int ThisSum = 0, MaxSum = 0;
	int N = a.size();
	Ret_max<T> ret;

	ret.i = 0; //default 0
	for (int i = 0; i < N; i++)
	{
		ThisSum += a[i];

		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
			ret.j = i; //��β
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;
			ret.i = i + 1; //��һ�����¿�ʼ����
		}
		//else 
	}
	ret.a = MaxSum;

	return ret;
}
