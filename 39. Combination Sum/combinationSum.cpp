/*
Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers 
sums to T.

The same repeated number may be chosen from C unlimited number 
of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Thougths: use back-tracing idea. Start from the rightmost element in the candidate 
// vector and look for target - candidiate[index] element in index between 0 and index
// (inclusively). Repeat until the target becomes 0. If it's less than 0, we terminate 
// the recursion, if equals to 0, then we have sucessfully found one. Otherwise, we repeat
// the above process. 

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
	{
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int> > ret;
		vector<int> set;
		helper(ret, candidates, target, set, candidates.size() - 1);
		return ret;
	}

	void helper(vector<vector<int> >& result, const vector<int>& candidates, int target, vector<int>& cur, int start)
	{
		if (target < 0) { return; }
		if (target == 0) { result.push_back(cur); }
		else
		{
			for (int i = start; i >= 0; i--)
			{
				if (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) { continue; }
				cur.push_back(candidates[i]);
				helper(result, candidates, target - candidates[i], cur, i);
				cur.pop_back();
			}
		}
	}
};

int main(void)
{
	int nums[] = {7, 4, 1, 2, 3, 6, 7};
	vector<int> vec(nums, nums + sizeof(nums) / sizeof(nums[0]));
	Solution s;
	vector<vector<int> > ret = s.combinationSum(vec, 7);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}