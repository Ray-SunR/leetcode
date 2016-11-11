/*
Given a sorted array of integers, find the starting and ending 
position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		int pos = bsearch(nums, target);
		cout << "pos: " << pos << endl;
		if (pos == -1) { ret.push_back(-1); ret.push_back(-1); return ret; }
		int left = pos;
		int right = pos;
		while (left >= 0 && nums[left] == target) { left--; }
		while (right < nums.size() && nums[right] == target) { right++; }
		ret.push_back(left + 1);
		ret.push_back(right - 1);
		return ret;
	}

	int bsearch(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() -1;
		while (left <= right)
		{
			int pivot = left + (right - left) / 2;
			if (nums[pivot] == target) { return pivot; }
			if (nums[pivot] < target) { left = pivot + 1; }
			else { right = pivot - 1; }
		}
		return -1;
	}
};

int main(void)
{
	int a[] = { 0,0,0,1,2,3 };
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
	Solution s;
	vector<int> ret  =s.searchRange(nums, 0);
	for (int i = 0;i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
	return 0;
}