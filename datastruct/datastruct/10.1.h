#ifndef __10_1_H__
#define __10_1_H__


#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>
#include "myiterator.h"
//#include <boost/lexical_cast.hpp>

namespace Main_10_1
{	//hash_map 采用取余法构建哈希值，采用二次探测解决哈希冲突
	using namespace std;

	template <class T>
	class my_map_int 
	{
	public:
		my_map_int(const pair<int, T>& empty, const pair<int, T>& tomb, int size = 8);
		~my_map_int();

		T& insert(int key, const T& value);
		void remove(const int key);
		T& operator[](int key);
		myiterator<pair<int, T>> CreateIterator();
		myiterator<pair<int, T>> begin();
		myiterator<pair<int, T>> end();

	private:
		pair<int, T>* HD;
		int M; //总个数
		int N; //现有个数
		float alpha; //负载因子
		int mod;
		const pair<int, T>& EMPTY;
		const pair<int, T>& TOMB;

		int& getkey(pair<int, T>& p);
		T& getvalue(pair<int, T>& p);
		int hash(int x) const;
		int probe(int x, int i) const;
		float alpha_get();
		void reset();
	};


	/**
	 * \brief
	 * \param size 初始大小
	 */
	template <class T>
	my_map_int<T>::
		my_map_int(const pair<int, T>& empty, const pair<int, T>& tomb, int size) : M(size), EMPTY(empty), TOMB(tomb)
	{
		N = 0;
		alpha = 0;
		HD = new pair<int, T>[M];
		for (int i = 0; i < M; i++)
		{
			HD[i] = EMPTY;
		}

		mod = M;
		while (mod % 2 == 0)
		{
			mod--;
			while (mod % 10 == 0)
				mod--;
		}
	}

	template <class T>
	my_map_int<T>::~my_map_int()
	{
		delete[]HD;
	}

	template <class T>
	T& my_map_int<T>::insert(const int key, const T& value)
	{
		if (alpha_get() > 0.5)
		{
			reset();
		}

		int home = hash(key);
		int pos = home;
		int i = 1;
		bool tomb = false;

		while (HD[pos] != EMPTY)
		{
			if (getkey(HD[pos]) == key)
			{
				getvalue(HD[pos]) = value;
				return getvalue(HD[pos]);
			}
			if (HD[pos] == TOMB)
			{
				tomb = true;
				break;
			}
			pos = probe(home, i++);
		}
		getkey(HD[pos]) = key;
		getvalue(HD[pos]) = value;
		if (tomb != true)
		{
			N++;
		}

		return getvalue(HD[pos]);
	}

	template <class T>
	void my_map_int<T>::remove(const int key)
	{
		int home = hash(key);
		int pos = home;
		int i = 1;
		bool tomb = false;

		while (HD[pos] != EMPTY)
		{
			if (getkey(HD[pos]) == key)
			{
				HD[pos] = TOMB;
				return;
			}
			pos = probe(home, i++);
		}
	}

	template <class T>
	T& my_map_int<T>::operator[](const int key)
	{
		// find element matching key or insert with default mapped
		return this->insert(key, T());
	}

	template <class T>
	int& my_map_int<T>::getkey(pair<int, T>& p)
	{
		return p.first;
	}

	template <class T>
	T& my_map_int<T>::getvalue(pair<int, T>& p)
	{
		return p.second;
	}

	template <class T>
	int my_map_int<T>::hash(int x) const
	{
		//cout << "hash(" << x << " ) = " << x % mod << endl;
		return x % mod;

		//return (M - 1) * ((0.6180339 * x) - (int)(0.6180339 * x));
	}

	template <class T>
	int my_map_int<T>::probe(int x, int i) const
	{
		int y = ((i + 1) / 2) * ((i + 1) / 2); //二次探测
		if (((i + 1) / 2) % 2 != 0)
		{
			//cout << "\t probe(" << x << ", " << i << " ) = " << abs((x + y) % M) << endl;
			return abs((x + y) % M);
		}
		//cout << "\t probe(" << x << ", " << i << " ) = " << abs((x - y) % M) << endl;
		return abs((x - y) % M);
	}

	template <class T>
	float my_map_int<T>::alpha_get()
	{
		alpha = static_cast<float>(N) / M;
		return alpha;
	}

	template <class T>
	void my_map_int<T>::reset()
	{
		int oldsize = M;

		M = M * 2;
		N = 0;
		mod = M;
		while (mod % 2 == 0)
		{
			mod--;
			while (mod % 10 == 0)
				mod--;
		}

		pair<int, T>* hd = new pair<int, T>[M];
		for (int i = 0; i < M; i++)
		{
			hd[i] = EMPTY;
		}
		for (int i = 0; i < oldsize; i++)
		{
			int home;
			if (HD[i] != EMPTY && HD[i] != TOMB)
				home = hash(getkey(HD[i]));
			else
				continue;
			int pos = home;
			int k = 1;

			while (hd[pos] != EMPTY)
			{
				pos = probe(home, k++);
			}
			hd[pos] = HD[i];
			N++;
		}
		delete[]HD;
		HD = hd;
	}

	template <class T>
	class MyIntMap_iterator;

	template <class T>
	myiterator<pair<int, T>> my_map_int<T>::CreateIterator()
	{
		return MyIntMap_iterator<pair<int, T>>(this->HD);
	}

	template <class T>
	myiterator<pair<int, T>> my_map_int<T>::begin()
	{
		return MyIntMap_iterator<pair<int, T>>(this->HD);
	}

	template <class T>
	myiterator<pair<int, T>> my_map_int<T>::end()
	{
		return MyIntMap_iterator<pair<int, T>>(this->HD + M);
	}

	template <class T>
	class MyIntMap_iterator : public myiterator<T>
	{
	public:
		explicit MyIntMap_iterator(T* _Parg)
			: myiterator<T>(_Parg)
		{
		}
	};

	void main_10_1();
}

#endif
