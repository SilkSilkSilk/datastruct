#ifndef __MAIN_9_1_H__
#define __MAIN_9_1_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include <queue>
//#include <boost/lexical_cast.hpp>

namespace Main_9_1
{	//排序
	using namespace std;

	template <class T>
	void swap(T& a, T& b) noexcept
	{
		a = a - b;
		b = a + b;
		a = b - a;
	}

	template <class T>
	void print(T array[], int n)
	{
		if (array == nullptr)
			return;
		for (int i = 0; i < n; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}

	/**
	 * \brief 插入排序
	 *  超出时间限制
	 * \tparam T
	 * \param array
	 * \param n
	 */
	template <class T>
	void improved_insert_sort(T array[], int n)
	{
		if (array == nullptr)
			return;
		T temp;
		for (int i = 1; i < n; i++)
		{
			temp = array[i];
			int j = i - 1;
			for (; j >= 0 && temp < array[j]; j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = temp;
		}
	}

	/**
	 * \brief 增量为/2的插入排序，使得插入排序重复比较的次数降低
	 *  80 ms	15.6 MB
	 * \tparam T
	 * \param array
	 * \param n
	 * \return 赋值次数
	 */
	template <class T>
	int shell_sort(T array[], int n)
	{
		if (array == nullptr)
			return -1;
		int op = 0;
		T temp;
		int j;
		for (int h = n / 2; h > 0; h /= 2)
		{
			for (int i = h; i < n; i++)
			{
				temp = array[i];
				for (j = i - h; j >= 0 && temp < array[j]; j -= h)
				{
					array[j + h] = array[j];
					op++;
				}
				array[j + h] = temp;
				op++;
			}
		}
		return op;
	}

	/**
	 * \brief 优化增量，使得比较重复的的次数减少
	 *  76 ms	15.6 MB
	 * \tparam T
	 * \param array
	 * \param n
	 * \return 赋值次数
	 */
	template <class T>
	int shell_sort_2(T array[], int n)
	{
		if (array == nullptr)
			return -1;
		int incs[16] = {
			/*a1=3,a2=7,a3=16,a4=41,a5=101*/
			1391376, /*a1*a2*a3*a4*a5*/
			463792, /*a2*a3*a4*a5*/
			198768, /*a1*a3*a4*a5*/
			86961, /*a1*a2*a4*a5*/
			33936, /*a1*a2*a3*a5*/
			13776, /*a1*a2*a3*a4*/
			4592, /*a2*a3*a4*/
			1968, /*a1*a3*a4*/
			861, /*a1*a2*a4*/
			336, /*a1*a2*a3*/
			112, /*a2*a3*/
			48, /*a1*a3*/
			21, /*a1*a2*/
			7, /*a2*/
			3, /*a1*/
			1
		};
		int op = 0;
		T temp;
		int j;
		int h;
		for (int t = 0; t < 16; t++)
		{
			h = incs[t];
			for (int i = h; i < n; i++)
			{
				temp = array[i];
				for (j = i - h; j >= 0 && temp < array[j]; j -= h)
				{
					array[j + h] = array[j];
					op++;
				}
				array[j + h] = temp;
				op++;
			}
		}
		return op;
	}

	/**
	 * \brief 选择排序
	 *  1900 ms	15.9 MB
	 * \tparam T
	 * \param array
	 * \param n
	 */
	template <class T>
	void select_sort(T array[], int n)
	{
		if (array == nullptr)
			return;
		int temp;
		int j;
		for (int i = 0; i < n - 1; i++)
		{
			temp = i;
			for (j = i + 1; j < n; j++)
			{
				if (array[temp] > array[j])
				{
					temp = j;
				}
			}
			if (temp != i)
			{
				array[i] = array[i] - array[temp];
				array[temp] = array[temp] + array[i];
				array[i] = array[temp] - array[i];
			}
		}
	}


	/**
	 * \brief 最小堆的库实现
	 *  112 ms	16.2 MB
	 * \tparam T
	 * \param array
	 * \param n
	 */
	template <class T>
	void heap_sort(T array[], int n)
	{
		struct greater1
		{
			bool operator()(const long& a, const long& b) const
			{
				return a > b;
			}
		};

		vector<T> heap(array, array + n);
		std::make_heap(heap.begin(), heap.end(), greater1());
		auto i = 0;
		while (!heap.empty())
		{
			std::pop_heap(heap.begin(), heap.end(), greater1());
			array[i++] = heap.back();
			heap.pop_back();
		}
	}

	template <class T>
	class MyMinHeap
	{
		T* elements = nullptr;
		int size;
		int capacity;

	public:
		MyMinHeap(const int maxsize)
		{
			elements = new T[maxsize + 1];
			elements[0] = 0;
			size = 0;
			capacity = maxsize;
		}

		~MyMinHeap()
		{
			if (elements != nullptr)
			{
				delete[] elements;
			}
		}

		bool isfull() const
		{
			return size == capacity ? true : false;
		}

		bool isEmpty() const
		{
			return size == 0 ? true : false;
		}

		void insert(T data)
		{
			if (isfull())
			{
				return;
			}
			if (data < elements[0])
			{
				elements[0] = data;
			}
			int i = ++size;
			for (; elements[i / 2] > data; i /= 2)
			{
				elements[i] = elements[i / 2];
			}
			elements[i] = data;
		}

		T delete_t()
		{
			if (isEmpty())
			{
				return T();
			}
			T minitem = elements[1];
			T temp = elements[size--];
			int parent = 1, child;
			for (; parent * 2 <= size; parent = child)
			{
				child = parent * 2;
				if (child != size && elements[child] > elements[child + 1])
				{
					child += 1;
				}
				if (elements[child] < temp)
				{
					elements[parent] = elements[child];
				}
				else
				{
					break;
				}
			}
			elements[parent] = temp;
			return minitem;
		}
	};

	/**
	 * \brief 最小堆的自我实现
	 *	执行用时 :44 ms, 在所有 C++ 提交中击败了79.97%的用户
	 *	内存消耗 :16.1 MB, 在所有 C++ 提交中击败了16.67%的用户
	 * \tparam T
	 * \param array
	 * \param n
	 */
	template <class T>
	void heap_sort_my(T array[], int n)
	{
		if (array == nullptr)
			return;
		MyMinHeap<T> my_min_heap(n);
		for (int i = 0; i < n; i++)
		{
			my_min_heap.insert(array[i]);
		}
		for (int i = 0; !my_min_heap.isEmpty(); i++)
		{
			array[i] = my_min_heap.delete_t();
		}
	}

	/**
	 * \brief 归并
	 * \tparam T
	 * \param src	源
	 * \param des	临时
	 * \param left
	 * \param mid
	 * \param right	包含
	 */
	template <class T>
	void merge_array(T src[], T des[], int left, int mid, int right)
	{
		if (src == nullptr || des == nullptr || left > mid || mid > right)
			return;
		for (int i = left; i <= mid; i++)
		{
			des[i] = src[i];
		}
		for (int i = mid + 1; i <= right; i++)
		{
			des[right - i + mid + 1] = src[i];
		}
		for (int index1 = left, index2 = right, des_index = left; des_index <= right; des_index++)
		{
			if (des[index1] <= des[index2])
			{
				src[des_index] = des[index1++];
			}
			else
			{
				src[des_index] = des[index2--];
			}
		}
	}

	/**
	 * \brief 归并排序-递归
	 * \tparam T
	 * \param array
	 * \param n
	 */
	template <class T>
	void merge_sort_recursion(T array[], T des[], int left, int right)
	{
		if (left == right)
		{
			return;
		}
		merge_sort_recursion(array, des, left, (left + right) / 2);
		merge_sort_recursion(array, des, (left + right) / 2 + 1, right);
		merge_array(array, des, left, (left + right) / 2, right);
	}

	/**
	 * \brief 归并排序-递归
	 *  执行用时 :48 ms, 在所有 C++ 提交中击败了73.93%的用户
	 *  内存消耗 :16.1 MB, 在所有 C++ 提交中击败了16.67%的用户
	 * \tparam T
	 * \param array
	 * \param n 尾后
	 */
	template <class T>
	void merge_sort_recursion(T array[], int n)
	{
		if (array == nullptr)
			return;

		auto des = new T[n];
		merge_sort_recursion(array, des, 0, n - 1);
		delete[]des;
	}

	/**
	 * \brief 2分查找+shell排序
	 * \tparam T
	 * \param array
	 * \param n 尾后
	 */
	template <class T>
	void shell_binary_sort_self(T array[], int n)
	{
		if (array == nullptr)
			return;

		for (int i = 1; i < n; i++)
		{
			//寻找位置
			int left = 0, right = i - 1, mid;
			while (left <= right)
			{
				mid = (left + right) / 2;
				if (array[mid] > array[i])
				{
					right = mid - 1;
				}
				else if (array[mid] < array[i])
				{
					left = mid + 1;
				}
				else
				{
					break;
				}
			}
			T temp = array[i];
			if (array[mid] <= array[i]) //右边
			{
				for (int j = i; j > mid + 1; j--)
				{
					array[j] = array[j - 1];
				}
				array[mid + 1] = temp;
			}
			else //左边
			{
				for (int j = i; j > mid; j--)
				{
					array[j] = array[j - 1];
				}
				array[mid] = temp;
			}
		}
	}

	/**
	 * \brief 桶排序
	 *  适合于数值紧凑的场合
	 * \tparam T
	 * \param array
	 * \param n 尾后
	* \param max 最大元素
	 */
	template <class T>
	void bucket_sort(T array[], int n, int max)
	{
		if (array == nullptr)
			return;

		T* temp = new T[n];
		int* count = new int[max];

		for (int i = 0; i < max; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			if (array[i] >= max)
				return;
			count[array[i]] += 1;
		}
		for (int i = 1; i < max; i++)
		{
			count[i] = count[i - 1] + count[i];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			count[array[i]] -= 1;
			temp[count[array[i]]] = array[i];
		}
		for (int i = 0; i < n; i++)
		{
			array[i] = temp[i];
		}
		delete[]count;
		delete[]temp;
	}

	/**
	 * \brief 桶排序-自我
	 * 我写了一个下午的代码，这应该算是shell排序的变种，将n次查找变成了2分查找，后面又加入了桶排序的知识。
	 * \tparam T
	 * \param array
	 * \param n 尾后
	 */
	template <class T>
	void bucket_sort_self(T array[], int n)
	{
		if (array == nullptr)
			return;

		struct bucket_node
		{
			T* data = nullptr;
			int count = 0;
		};
		int form_index = 0;
		bucket_node* form = new bucket_node[n];
		form[0].data = &array[0];
		++form[0].count;
		form_index++;
		for (int i = 1; i < n; i++)
		{
			//寻找位置
			int left = 0, right = form_index - 1, mid;
			while (left <= right)
			{
				mid = (left + right) / 2;
				if (form[mid].data != nullptr)
				{
					if (*form[mid].data > array[i])
					{
						right = mid - 1;
					}
					else if (*form[mid].data < array[i])
					{
						left = mid + 1;
					}
					else
					{
						break;
					}
				}
				else
				{
					right = mid - 1;
				}
			}
			if (left <= right) //找到了
			{
				++form[mid].count;
			}
			else
			{
				if (*form[mid].data < array[i]) //右边
				{
					for (int j = form_index; j > mid + 1; j--)
					{
						form[j] = form[j - 1];
					}
					form[mid + 1].data = &array[i];
					form[mid + 1].count = 1;
					form_index++;
				}
				else //左边
				{
					for (int j = form_index; j > mid; j--)
					{
						form[j] = form[j - 1];
					}
					form[mid].data = &array[i];
					form[mid].count = 1;
					form_index++;
				}
			}
		}
		T* temp = new T[n];
		for (int i = 0, j = 0; form[i].data != nullptr && i < form_index;)
		{
			if (form[i].count > 0)
			{
				temp[j++] = *form[i].data;
				--form[i].count;
			}
			else
			{
				i++;
			}
		}
		delete[]form;
		for (int i = 0; i < n; i++)
		{
			array[i] = temp[i];
		}
	}

	/**
	 * \brief 基数桶排序
	 *  将数值按个 十 百拆分，然后进行n次桶排序，这样只需要每次10个桶就可以了，是为了防止数据比较离散
	 * \tparam T
	 * \param array
	 * \param n 尾后
	 * \param d 最大位数 表示最多多少次桶排序
	 * \param r
	 */
	template <class T>
	void radix_sort(T array[], const int n, int d, int r)
	{
		if (array == nullptr)
			return;

		int radix = 1;
		T* temp = new T[n];
		int* count = new int[r];
		int k;

		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < r; j++)
			{
				count[j] = 0;
			}
			for (int j = 0; j < n; j++)
			{
				count[(array[j] / radix) % r] += 1;
			}
			for (int j = 1; j < r; j++)
			{
				count[j] = count[j - 1] + count[j];
			}
			for (int j = n - 1; j >= 0; j--)
			{
				k = (array[j] / radix) % r;
				count[k] -= 1;
				temp[count[k]] = array[j];
			}
			for (int j = 0; j < n; j++)
			{
				array[j] = temp[j];
			}
			radix *= r;
		}
		delete[]count;
		delete[]temp;
	}

	/**
	 * \brief 快速排序
	 *  轴值左边的小于轴值，轴值右边的大于轴值
	 * \tparam T
	 * \param array
	 * \param left start
	 * \param right end 包含
	 */
	template <class T>
	void quick_sort(T array[], const int left, const int right)
	{
		if (left >= right)
			return;

		int axis = (left + right) / 2;
		T temp = array[axis];
		array[axis] = array[right];
		int action = left;
		int l = left, r = right;
		while (r - l > 0)
		{
			if (action == l)
			{
				if (array[l] > temp)
				{
					array[r] = array[l];
					r--;
					action = r;
				}
				else
				{
					l++;
					action = l;
				}
			}
			else
			{
				if (array[r] < temp)
				{
					array[l] = array[r];
					l++;
					action = l;
				}
				else
				{
					r--;
					action = r;
				}
			}
		}
		array[l] = temp;
		axis = l;

		//fen
		quick_sort(array, left, axis - 1);
		quick_sort(array, axis + 1, right);
	}

	/**
	 * \brief 快速排序，轴值左边的小于轴值，轴值右边的大于轴值
	 *  执行用时 :44 ms, 在所有 C++ 提交中击败了81.53%的用户
	 *  内存消耗 :15.8 MB, 在所有 C++ 提交中击败了16.67%的用户
	 * \tparam T
	 * \param array
	 * \param n
	 */
	template <class T>
	void quick_sort(T array[], const int n)
	{
		if (array == nullptr)
			return;

		quick_sort(array, 0, n - 1);
	}

	/**
	 * \brief 快速排序-shell优化
	 * \tparam T
	 * \param array
	 * \param left start
	 * \param right end 包含
	 */
	template <class T>
	void quick_shell_sort(T array[], const int left, const int right)
	{
		if (right - left > 32)
		{
			int axis = (left + right) / 2;
			T temp = array[axis];
			array[axis] = array[right];
			int action = left;
			int l = left, r = right;
			while (r - l > 0)
			{
				if (action == l)
				{
					if (array[l] > temp)
					{
						array[r] = array[l];
						r--;
						action = r;
					}
					else
					{
						l++;
						action = l;
					}
				}
				else
				{
					if (array[r] < temp)
					{
						array[l] = array[r];
						l++;
						action = l;
					}
					else
					{
						r--;
						action = r;
					}
				}
			}
			array[l] = temp;
			axis = l;

			//fen
			quick_shell_sort(array, left, axis - 1);
			quick_shell_sort(array, axis + 1, right);
		}
		else
		{
			for (int i = left + 1; i <= right; i++)
			{
				//寻找位置
				int l = left, r = i - 1, mid;
				while (l <= r)
				{
					mid = (l + r) / 2;
					if (array[mid] > array[i])
					{
						r = mid - 1;
					}
					else if (array[mid] < array[i])
					{
						l = mid + 1;
					}
					else
					{
						break;
					}
				}
				T temp = array[i];
				if (array[mid] <= array[i]) //右边
				{
					for (int j = i; j > mid + 1; j--)
					{
						array[j] = array[j - 1];
					}
					array[mid + 1] = temp;
				}
				else //左边
				{
					for (int j = i; j > mid; j--)
					{
						array[j] = array[j - 1];
					}
					array[mid] = temp;
				}
			}
		}
	}

	/**
	 * \brief 快速排序-shell优化
	 * 执行用时 :44 ms, 在所有 C++ 提交中击败了81.53%的用户
	 * 内存消耗 :15.8 MB, 在所有 C++ 提交中击败了16.67%的用户
	 * \tparam T
	 * \param array
	 * \param n
	 */
	template <class T>
	void quick_shell_sort(T array[], const int n)
	{
		if (array == nullptr)
			return;

		quick_shell_sort(array, 0, n - 1);
	}

	void main_9_1();
}

#endif
