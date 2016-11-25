/*
Given n non-negative integers representing an elevation map where the width of 
each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int min(int a, int b)
	{
		return a < b ? a : b;
	}

	int trap(vector<int>& water) {
		int i = 0; int j = water.size() - 1;
		int left_max = i; int right_max = j;
		int ret = 0;
		while (i <= j)
		{
			if (water[left_max] < water[right_max])
			{
				if (water[i] > water[left_max])
				{
					left_max = i;
				}
				else
				{
					ret += water[left_max] - water[i];
				}
				i++;
			}
			else
			{
				if (water[j] > water[right_max])
				{
					right_max = j;
				}
				else
				{
					ret += water[right_max] - water[j];
				}
				j--;
			}
		}
		return ret;
	}
};

int main(void)
{
	//int water[] = {1, 2, 3, 4, 5, 6, 0, 0, 0, 9, 0, 1, 2, 3, 4, 6};
	int water[] = {4, 2, 3};
	vector<int> vec(water, water + sizeof(water) / sizeof(water[0]));
	Solution s;
	cout << s.trap(vec) << endl;
	return 0;
}