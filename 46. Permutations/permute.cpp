/*
Given a collection of distinct numbers, return all possible permutations.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > permute(const vector<int>& nums) 
	{
		vector<vector<int> > result;
		if (nums.size() == 1) { result.push_back(nums); return result; }
		vector<vector<int> > others = permute(vector<int>(nums.begin() + 1, nums.end()));
		for (int i = 0;i < others.size(); i++)
		{
			vector<int>& target = others[i];
			for (int j = 0; j < target.size() + 1; j++)
			{
				vector<int> toadd = target;
				toadd.insert(toadd.begin() + j, nums[0]);
				result.push_back(toadd);
			}
		}
		return result;
	}
};

int main(void)
{
	int a[] = {1, 2, 3};
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
	Solution s;
	vector<vector<int> > result = s.permute(nums);
	for (int i = 0;i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}