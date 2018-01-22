#ifndef __MAIN_2_2_H__
#define __MAIN_2_2_H__


namespace Main_2_2
{//线性表操作
	typedef int ElementType;
#define MAXSIZE 1024


	struct LNode
	{
		ElementType Data[MAXSIZE];
		int Last;
	};


	typedef struct LNode* List;

	//struct LNode L;
	//List PtrL;

	List MakeEmpty();
	int Find(const ElementType x, const List ptrl);
	void insert(const ElementType x, const int i, List const ptrl);
	void Delete(const int i, List const ptrl);
	void print(List const ptrl);
	int main_2_2();
}


#endif
