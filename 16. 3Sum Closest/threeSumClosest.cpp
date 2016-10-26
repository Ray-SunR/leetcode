/*
Given an array S of n integers, find three integers in S such that
 the sum is closest to a given number, target. Return the sum of 
 the three integers. You may assume that each input would have 
 exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int i = 0;
		int cloest_sum = nums[0] + nums[1] + nums[2];
		std::sort(nums.begin(), nums.end());
		while (i < nums.size())
		{
			int mytarget = target - nums[i];
			int j = i + 1;
			int jend = nums.size() - 1;
			while (j < jend)
			{
					// perfect match
				if (nums[j] + nums[jend] == mytarget)
				{
					return target;
				}
				else
				{
					cout << "j : " << nums[j] << " jend: " << nums[jend] << " i: " << nums[i] << endl;
					if (abs(nums[j] + nums[jend] + nums[i] - target) < abs(cloest_sum - target))
					{
						cloest_sum = nums[j] + nums[jend] + nums[i];
					}
					if (nums[j] + nums[jend] > mytarget)
					{
						jend--;
					}
					else
					{
						j++;
					}
				}
			}
			i++;
		}
		return cloest_sum;
	}

	int abs(int val)
	{
		return val < 0 ? -val : val;
	}
};

int main(void)
{
	int a[] = {-3,-2,-5,3,-4};
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
	Solution s;
	cout << s.threeSumClosest(nums, -1) << endl;
	return 0;
}