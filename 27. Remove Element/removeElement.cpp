/*
Given an array and a value, remove all instances of that value 
in place and return the new length.

Do not allocate extra space for another array, you must do this 
in place with constant memory.

The order of elements can be changed. It doesn't matter what you 
leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements
of nums being 2.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int p1,p2;
		p1 = 0; p2 = 0;
		while (p2 < nums.size())
		{
			if (nums[p2] != val) { nums[p1] = nums[p2]; p1++; }
			p2++;
		}
		return p1;
	}
};

int main(void)
{
	int a[] = { 1, 2, 3, 4, 3, 4, 4, 3, 3, 3, 3};
	vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
	Solution s;
	int size = s.removeElement(vec, 1);
	for (int i = 0;i < size; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}