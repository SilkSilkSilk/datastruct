#include "Leetcode.h"
#include <deque>
#include "9.1.h"

class Solution
{
public:
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
};

void main_Leetcode()
{
	Solution solution;
	cout << solution.isValid(string("(){}[]")) << endl;
}

