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
{	//����
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
	 * \brief ��������
	 *  ����ʱ������
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
	 * \brief ����Ϊ/2�Ĳ�������ʹ�ò��������ظ��ȽϵĴ�������
	 *  80 ms	15.6 MB
	 * \tparam T
	 * \param array
	 * \param n
	 * \return ��ֵ����
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
	 * \brief �Ż�������ʹ�ñȽ��ظ��ĵĴ�������
	 *  76 ms	15.6 MB
	 * \tparam T
	 * \param array
	 * \param n
	 * \return ��ֵ����
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
	 * \brief ѡ������
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
	 * \brief ��С�ѵĿ�ʵ��
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
	 * \brief ��С�ѵ�����ʵ��
	 *	ִ����ʱ :44 ms, ������ C++ �ύ�л�����79.97%���û�
	 *	�ڴ����� :16.1 MB, ������ C++ �ύ�л�����16.67%���û�
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
	 * \brief �鲢
	 * \tparam T
	 * \param src	Դ
	 * \param des	��ʱ
	 * \param left
	 * \param mid
	 * \param right	����
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
	 * \brief �鲢����-�ݹ�
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
	 * \brief �鲢����-�ݹ�
	 *  ִ����ʱ :48 ms, ������ C++ �ύ�л�����73.93%���û�
	 *  �ڴ����� :16.1 MB, ������ C++ �ύ�л�����16.67%���û�
	 * \tparam T
	 * \param array
	 * \param n β��
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
	 * \brief 2�ֲ���+shell����
	 * \tparam T
	 * \param array
	 * \param n β��
	 */
	template <class T>
	void shell_binary_sort_self(T array[], int n)
	{
		if (array == nullptr)
			return;

		for (int i = 1; i < n; i++)
		{
			//Ѱ��λ��
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
			if (array[mid] <= array[i]) //�ұ�
			{
				for (int j = i; j > mid + 1; j--)
				{
					array[j] = array[j - 1];
				}
				array[mid + 1] = temp;
			}
			else //���
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
	 * \brief Ͱ����
	 *  �ʺ�����ֵ���յĳ���
	 * \tparam T
	 * \param array
	 * \param n β��
	* \param max ���Ԫ��
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
	 * \brief Ͱ����-����
	 * ��д��һ������Ĵ��룬��Ӧ������shell����ı��֣���n�β��ұ����2�ֲ��ң������ּ�����Ͱ�����֪ʶ��
	 * \tparam T
	 * \param array
	 * \param n β��
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
			//Ѱ��λ��
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
			if (left <= right) //�ҵ���
			{
				++form[mid].count;
			}
			else
			{
				if (*form[mid].data < array[i]) //�ұ�
				{
					for (int j = form_index; j > mid + 1; j--)
					{
						form[j] = form[j - 1];
					}
					form[mid + 1].data = &array[i];
					form[mid + 1].count = 1;
					form_index++;
				}
				else //���
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
	 * \brief ����Ͱ����
	 *  ����ֵ���� ʮ �ٲ�֣�Ȼ�����n��Ͱ��������ֻ��Ҫÿ��10��Ͱ�Ϳ����ˣ���Ϊ�˷�ֹ���ݱȽ���ɢ
	 * \tparam T
	 * \param array
	 * \param n β��
	 * \param d ���λ�� ��ʾ�����ٴ�Ͱ����
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
	 * \brief ��������
	 *  ��ֵ��ߵ�С����ֵ����ֵ�ұߵĴ�����ֵ
	 * \tparam T
	 * \param array
	 * \param left start
	 * \param right end ����
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
	 * \brief ����������ֵ��ߵ�С����ֵ����ֵ�ұߵĴ�����ֵ
	 *  ִ����ʱ :44 ms, ������ C++ �ύ�л�����81.53%���û�
	 *  �ڴ����� :15.8 MB, ������ C++ �ύ�л�����16.67%���û�
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
	 * \brief ��������-shell�Ż�
	 * \tparam T
	 * \param array
	 * \param left start
	 * \param right end ����
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
				//Ѱ��λ��
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
				if (array[mid] <= array[i]) //�ұ�
				{
					for (int j = i; j > mid + 1; j--)
					{
						array[j] = array[j - 1];
					}
					array[mid + 1] = temp;
				}
				else //���
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
	 * \brief ��������-shell�Ż�
	 * ִ����ʱ :44 ms, ������ C++ �ύ�л�����81.53%���û�
	 * �ڴ����� :15.8 MB, ������ C++ �ύ�л�����16.67%���û�
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
