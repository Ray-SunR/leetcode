/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > ret;
		std::sort(nums.begin(), nums.end());
		int i = 0;
		while (i < nums.size())
		{
			if (i == 0 || nums[i] != nums[i - 1])
			{
				int target = -nums[i];
				int j = i + 1;
				int jend = nums.size() - 1;
				while (j < jend)
				{
					if (nums[j] + nums[jend] == target)
					{
						vector<int> found;
						found.push_back(nums[i]);
						found.push_back(nums[j]);
						found.push_back(nums[jend]);
						ret.push_back(found);
						j++;
						jend--;
						while (j < jend && nums[j] == nums[j - 1]) { j++; }
						while (j < jend && nums[jend] == nums[jend + 1]) { jend--; }
					}
					else if (nums[j] + nums[jend] > target)
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
		return ret;
	}
};

int main(void)
{
	//-4 -1 -1 0 1 2 
	const int a[] = { -1, 0, 1, 2, -1, -4 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	Solution s;
	vector<vector<int> > ret = s.threeSum(v);
	for (int i = 0;i < ret.size(); i++)
	{
		for (int j = 0;j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}