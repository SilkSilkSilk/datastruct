#include "Leetcode.h"
#include <deque>
#include "9.1.h"

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		deque<int> dq;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			int k = nums.size() - 1;
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (j != i + 1 && nums[j] == nums[j - 1])
					continue;
				while (-(nums[i] + nums[j]) > nums[k])
				{
					k--;
				}
				if (k <= j)
					break;
				dq.push_back(nums[i] + nums[j] + nums[k]);
			}
		}
		if (dq.size() == 0)
			return 0;

		Main_9_1::quick_shell_sort(&dq, dq.size()); //¿ìËÙ+shell 32ÅÅÐò
		int left = 0, right = dq.size() - 1, mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (dq[mid] > target)
			{
				right = mid - 1;
			}
			else if (dq[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				return target;
			}
		}
		if (left == dq.size())
		{
			return dq.back();
		}
		return dq[left];
	}
};

void main_Leetcode()
{
	Solution solution;
	vector<int> vr = {-1, 3, 5, 8, 0, 2, 1, -4};
	cout << solution.threeSumClosest(vr, 1) << endl;
}
