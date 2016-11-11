/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int pivot = left + (right - left) / 2;
			if (nums[pivot] == target) { return pivot; }
			if (nums[pivot] < target) 
			{
				left = pivot + 1; 
			}
			else 
			{
				right = pivot - 1; 
			}
			if (right < left)
			{
				if (target > nums[pivot]) { return pivot + 1;}
				else { return pivot; }
			}
		}
		return -1;
	}
};

int main(void)
{
	int a[] = { 1, 3, 5, 7, 9, 11};
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
	Solution s;
	cout << s.searchInsert(nums, 2) << endl;
	return 0;
}