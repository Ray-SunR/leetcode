/*
Given a sorted array, remove the duplicates in place such 
that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do 
this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two 
elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>
using namespace std;

// 1 1 2 3 3 4 4 5
// 
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) { return 0; }
		int p1,p2;
		p1 = 0;p2 = 0;
		while (p1 < nums.size())
		{
			int next = p1 + 1;
			int k = p2;
			while (p2 < nums.size() && nums[p2] == nums[k]) { p2++; }
			if (p2 < nums.size())
			{
				nums[next] = nums[p2];
				p1 = next;
			}
			else
			{
				return p1 + 1;
			}
		}
		return p1 + 1;
	}
};

int main(void)
{
	int a[] = {0, 1, 2, 2, 2, 3, 3, 3 };
	vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
	Solution s;
	int size = s.removeDuplicates(vec);
	for (int i = 0;i < size; i++)
	{
		cout << vec[i] << " ";
	}
	cout <<endl;
	return 0;
}