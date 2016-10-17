/*
Given an array of integers, return indices of the two numbers 
such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,
[0, 2, 5, 0] target = 0 -> return [0, 3]
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(const vector<int>& nums, int target)
	{
		map<int, int> hash;
		vector<int> ret;
		for (int i = 0;i < nums.size(); i++)
		{
			map<int, int>::const_iterator it = hash.find(target - nums[i]);
			if (it != hash.end())
			{
				ret.push_back(it->second);
				ret.push_back(i);
			}
			else
			{
				hash[nums[i]] = i;
			}
		}
		return ret;
	}
};

int main(void)
{
	int values[] = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
	int values1[] = {0, 2, 3, 0, 3, 2, 5};
	vector<int> test(&values[0], &values[0] + sizeof(values) / sizeof(values[0]));
	vector<int> test1(&values1[0], &values1[0] + sizeof(values1) / sizeof(values1[0]));
	Solution s;
	vector<int> ret = s.twoSum(test1, 0);
	for (int i = 0;i < ret.size(); i++)
	{
		cout << ret[i] << " " << endl;
	}
	return 0;
}