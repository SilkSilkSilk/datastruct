#include "2.4.h"


namespace Main_2_4
{//�������-����ɾ����
	List MakeEmpty(const ElementType x)
	{
		List ptrL = nullptr;
		ptrL = new LNode();
		ptrL->Data = x;
		ptrL->next = nullptr;
		return ptrL;
	}


	//��0��ʼ
	int length(List ptrl)
	{
		List p = ptrl;
		int i = 0;
		while (p->next)
		{
			p = p->next;
			i++;
		}

		return i;
	}


	//k��0��ʼ��
	List FindKth(const int k, List ptrl)
	{
		List p = ptrl;
		int i = 0;

		while (p != nullptr && i < k)
		{
			p = p->next;
			i++;
		}

		if (i == k)
		{
			return p;
		}

		return nullptr;
	}


	List Find(ElementType x, List ptrl)
	{
		List p = ptrl;

		while (p != nullptr && p->Data != x)
		{
			p = p->next;
		}

		return p;
	}


	List insert(const ElementType x, const int i, List ptrl)
	{
		List p = nullptr, s = nullptr;

		if (i == 0)
		{
			s = new LNode;
			s->Data = x;
			s->next = ptrl;
		}

		p = FindKth(i - 1, ptrl);

		if (p == nullptr)
		{
			cout << "data error" << endl;
			return nullptr;
		}

		s = new LNode;
		s->Data = x;
		s->next = p->next;			//p->next��p+1  �Ȼ�ȡp+1����Ȼ�ᶪ��p+1
		p->next = s;

		return s; //���ز������ݵ�λ��
	}

	List Delete(const int i, List ptrl)
	{
		List p = nullptr, s = nullptr;

		if (i == 0)
		{
			s = ptrl;
			if (ptrl != nullptr)
			{
				ptrl = ptrl->next;
			}
			else
			{
				return  nullptr;
			}

			delete s;
			return ptrl;
		}

		p = FindKth(i - 1, ptrl);

		if (p == nullptr)
		{
			cout << "list " << i - 1 << " is empty" << endl;
			return nullptr;
		}
		else if(p->next == nullptr)
		{
			cout << "list " << i << " is empty" << endl;
			return nullptr;
		}
		else
		{
			s = p->next;
			p->next = s->next;

			delete s;

			return ptrl;
		}
	}
	
	void print(List ptrl)
	{
		List s = ptrl;

		while (s != nullptr)
		{
			cout << s->Data;
			s = s->next;
		}
		cout << endl;
	}

	int main_2_4()		//�������-����ɾ����
	{
		List ptrl = MakeEmpty(1);

		insert(2, 1, ptrl);
		insert(3, 2, ptrl);
		insert(4, 3, ptrl);
		insert(5, 4, ptrl);

		print(ptrl);

		cout << "length is " << length(ptrl) << endl;

		ptrl = Delete(0, ptrl);			//2345
		print(ptrl);

		ptrl = Delete(3, ptrl);			//234
		print(ptrl);

		cout << "length is " << length(ptrl) << endl;

		ptrl = Delete(3, ptrl);			//��ʱ�Ѿ�û�е�3����

		return 0;
	}
}
