#include "Leetcode.h"
#include <deque>
#include "9.1.h"

class Solution
{
public:
	//Á´½Ó£ºhttps ://leetcode-cn.com/problems/3sum-closest
	int threeSumClosest(vector<int>& nums, int target)
	{
		deque<int> dq;
		int value = 0;
		int v_abs_min = -1;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j < nums.size() - 1; j++)
			{
				if (j != i + 1 && (nums[j] == nums[j - 1]))
					continue;
				// while (j < k && -(nums[i] + nums[j]) < nums[k])
				// {
				// 	k--;
				// }
				// if (k == j)
				// 	break;
				for (int k = nums.size() - 1; k > j; k--)
				{
					const int abc = nums[i] + nums[j] + nums[k];
					if (v_abs_min == -1 || abs(abc - target) < v_abs_min)
					{
						v_abs_min = abs(abc - target);
						value = abc;
					}
				}
			}
		}
		return value;
	}

	//Á´½Ó£ºhttps://leetcode-cn.com/problems/valid-parentheses
	bool isValid(string s) {
		int n = s.size();
		if (n == 0)
			return true;
		if (n % 2 != 0)
			return false;
		for (auto &ch : s)
		{
			if (ch == '(')
				ch = 1;
			else if (ch == ')')
				ch = -1;
			else if (ch == '{')
				ch = 2;
			else if (ch == '}')
				ch = -2;
			else if (ch == '[')
				ch = 3;
			else if (ch == ']')
				ch = -3;
			else
				return false;
		}
		stack<int8_t> stk;
		for (int i = 0; i < n; i++)
		{
			if (s[i] > 0)
				stk.push(s[i]);
			else if (s[i] < 0)
			{
				if (stk.empty())
					return false;
				if (-stk.top() != s[i])
					return false;
				stk.pop();
			}
		}
		return stk.empty();
	}


	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	template <class T>
	class MyMinHeap
	{
		T* elements = nullptr;
		int size;
		int capacity;

	public:
		MyMinHeap(const int maxsize, T min)
		{
			elements = new T[maxsize + 1];
			elements[0] = min;
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

	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty())
			return nullptr;
		ListNode* ret = nullptr;
		ListNode* ret_r = nullptr;
		struct ListNodeP{
			ListNode *ptr;
			ListNodeP() :ptr(nullptr) { }
			ListNodeP(ListNode *p):ptr(p) {}
			bool operator<(const ListNodeP& l)
			{
				return this->ptr->val < l.ptr->val;
			}
			bool operator>(const ListNodeP& l)
			{
				return this->ptr->val > l.ptr->val;
			}
		};
		ListNode min(0);
		MyMinHeap<ListNodeP> heap(lists.size(), ListNodeP(&min));
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i])
				heap.insert(ListNodeP(lists[i]));
		}
		while (!heap.isEmpty())
		{
			auto ptr = heap.delete_t().ptr;
			if (ptr->next)
			{
				heap.insert(ListNodeP(ptr->next));
			}
			if (ret)
			{
				ret->next = ptr;
				ret = ret->next;
			}
			else
			{
				ret = ptr;
				ret_r = ret;
			}
		}
		return ret_r;
	}

	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return 1;
		uint32_t i = 0;
		for( ; i < nums.size() - 1;)
		{
			if (nums[i] == nums[i + 1])
			{
				nums.erase(nums.begin() + i + 1);
			}
			else
			{
				i++;
				continue;
			}
		}
		return i + 1;
	}

	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;

		int dir_t, dir_m;
		if (target > nums[0])
		{
			dir_t = 1;
		}
		else if(target < nums[0])
		{
			dir_t = 2;
		}
		else
		{
			return 0;
		}

		int left = 0, right = nums.size() - 1, mid;

		while(left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] >= nums[0])
			{
				dir_m = 1;
			}
			else
			{
				dir_m = 2;
			}

			if (dir_m == dir_t)
			{
				if (target > nums[mid])
				{
					if (dir_t == 1)
					{
						left = mid + 1;
					}
					else
					{
						left = mid + 1;
						while (left <= right)
						{
							mid = (left + right) / 2;
							if (nums[mid] < target)
							{
								left = mid + 1;
							}
							else if (nums[mid] > target)
							{
								right = mid - 1;
							}
							else
							{
								return mid;
							}
						}
						return -1;
					}
					
				}
				else if (target < nums[mid])
				{
					if (dir_t == 1)
					{
						right = mid - 1;
						while (left <= right)
						{
							mid = (left + right) / 2;
							if (nums[mid] < target)
							{
								left = mid + 1;
							}
							else if (nums[mid] > target)
							{
								right = mid - 1;
							}
							else
							{
								return mid;
							}
						}
						return -1;
					}
					else
					{
						right = mid - 1;
					}
				}
				else
				{
					return mid;
				}
			}
			else
			{
				if (dir_t == 1)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
				
			}
		}
		return -1;
	}
};

void main_Leetcode()
{
	Solution solution;
	vector<int> vr = { 5, 6, 7, 8, 9, 10, 0, 1 };
	cout << solution.search(vr, 5) << endl;
}

