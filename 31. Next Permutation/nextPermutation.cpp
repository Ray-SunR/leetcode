/*
Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible 
order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
 outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

// Thoughts: imagine there is window that covers numbers from end to index x towards
// the beginning (x >= 0), our job is to find the first non-descreasing (3, 7, 2) value from 
// (x, end) (x >= 0 && x <= end - 1). In the case of (3, 7, 2), the non-descreasing index is 
// pointing to 3. Then we need to find the smallest number in the right that bigger than the 
// current index. Once we found it, we swap these two values (7, 3, 2). Then, we need to sort
// the values starting from index + 1 in ascending order.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums)
	{
		int i = nums.size() - 1;
		while (i >= 0)
		{
			int min = INT_MAX;
			int pos = -1;
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] < min && nums[j] > nums[i])
				{
					min = nums[j];
					pos = j;
				}
			}
			if (pos != -1)
			{
				int tmp = nums[i];
				nums[i] = nums[pos];
				nums[pos] = tmp;
				std::sort(nums.begin() + i + 1, nums.end());
				return;
			}
			i--;
		}
		std::sort(nums.begin(), nums.end());
		
	}

	void nextPermutation1(vector<int>& nums)
	{
		// starting from the back.
		int i = nums.size() - 1;
		int pos = -1;
		int j = i - 1;
		while (j >= 0)
		{
			if (nums[i] > nums[j])
			{
				// easy case
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
				pos = j;
				break;
			}
			else
			{
				// now we have a sub array (j, end), see if we can find
				// anything here
				int min = INT_MAX;
				int idx = -1;
				for (int k = j + 1; k < nums.size(); k++)
				{
					if (nums[k] < min && nums[k] > nums[j])
					{
						min = nums[k]; idx = k;
					}
				}
				if (idx != -1)
				{
					int tmp = nums[idx];
					nums[idx] = nums[j];
					nums[j] = tmp;
					pos = j;
					break;
				}
			}
			j--;
		}
		sort(nums, pos + 1, nums.size());
	}

	void sort(vector<int>& nums, int begin, int end)
	{
		std::sort(nums.begin() + begin, nums.begin() + end);
	}
};

void Print(const vector<int>& nums)
{
	for (int i = 0;i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int nums[] = {2,1,2,2,2,2,2,1};
	int nums1[] = {4, 3, 2, 1};
	int nums2[] = {1, 3, 4, 5, 8, 4, 3};
	vector<int> vnums(nums, nums + sizeof(nums) / sizeof(nums[0]));
	vector<int> vnums1(nums1, nums1 + sizeof(nums1) / sizeof(nums1[0]));
	vector<int> vnums2(nums2, nums2 + sizeof(nums2) / sizeof(nums2[0]));
	Solution s;
	s.nextPermutation(vnums);
	Print(vnums);
	s.nextPermutation(vnums1);
	Print(vnums1);
	s.nextPermutation(vnums2);
	Print(vnums2);
	return 0;
}