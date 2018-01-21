#ifndef __MAIN_2_4_H__
#define __MAIN_2_4_H__

#include <iostream>


namespace Main_2_4
{
	using namespace std;

	typedef int ElementType;

	typedef struct LNode* List;


	struct LNode
	{
		ElementType Data;
		struct LNode* next;
	};

	List MakeEmpty(const ElementType x);
	int length(List ptrl);
	List FindKth(const int k, List ptrl);
	List Find(ElementType x, List ptrl);
	List insert(const ElementType x, const int i, List ptrl);
	List Delete(const int i, List ptrl);
	void print(List ptrl);
	int main_2_4();
}


#endif
