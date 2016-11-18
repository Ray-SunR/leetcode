/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) { return 1; }
		if (nums.size() == 1) { return nums[0] == 1 ? 2 : 1; }
		int i = 0;
		while (i < nums.size())
		{
			while (nums[i] > 0 && nums[i] != i 
				&& nums[i] < nums.size() // check within bounds
				&& nums[i] != nums[nums[i]]) // avoid duplicates
			{
				swap(nums[i], nums[nums[i]]);
			}
			i++;
		}

		for (int i = 1;i < nums.size(); i++)
		{
			if (nums[i] != i)
			{
				return i;
			}
		}

		// for handling [2, 1] or [3, 1, 2] cases.
		return nums.back() + 1 == nums[0] ? nums[0] + 1 : nums.back() + 1;
	}
};

// 3 1 2 3 4 5 
int main(void)
{
	int a[] = {3, 1, 2, 3, 4, 5};
	vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
	Solution s;
	cout << s.firstMissingPositive(vec) << endl;
	return 0;
}