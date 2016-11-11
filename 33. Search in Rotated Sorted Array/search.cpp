/*
Suppose a sorted array is rotated at some pivot unknown to you 
beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 3).

You are given a target value to search. If found in the array return 
its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include <iostream>
#include <vector>

using namespace std;

//4 5 6 7 0 1 2 3
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			//cout << "left: " << nums[left] << " right: " << nums[right] << endl;
			int pivot = left + (right - left) / 2;
			if (nums[pivot] == target) { return pivot; }
			if (nums[left] == target) { return left; }
			if (nums[right] == target) { return right; }
			if (nums[pivot] > nums[left])
			{
				// left part is sorted, the leftmost is the smallest on the left
				if (target < nums[pivot] && target > nums[left])
				{
					right = pivot - 1;
				}
				else
				{
					left = pivot + 1;
				}
			}
			else if (nums[pivot] < nums[right])
			{
				// right part is sorted, the rightmost is the largest on the right
				if (target > nums[pivot] && target < nums[right])
				{
					left = pivot + 1;
				}
				else
				{
					right = pivot - 1;
				}
			}
			else
			{
				return -1;
			}
		}
		return -1;
	}
};

int main(void)
{
	int a[] = { 4, 5, 6, 7, 0, 1, 2, 3 };
	int b[] = { 2, 3, 4, 5, 6, 7, 1 };
	vector<int> nums1(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> nums2(b, b + sizeof(b) / sizeof(b[0]));
	Solution s;
	for (int i = 0;i < nums2.size(); i++)
	{
		cout << s.search(nums2, nums2[i]) << endl;
	}

	//cout << s.search(nums2, 3) << endl;
	return 0;
}