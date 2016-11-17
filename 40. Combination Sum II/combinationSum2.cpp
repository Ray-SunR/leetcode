/*
Given a collection of candidate numbers (C) and a target number (T), find all unique
 combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

// Thoughts: sames as combination1 except that we have an extra parameter holding
// the previous poped value. The previous poped value means either a sucessfully
// pushed or an unsucessful pushed. If it was an unsuccessful pushed, then nothing matters
// if this is a successful puhsed, then this element should not be considered in the next
// recursion because the array is sorted.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int> > result;
		vector<int> set;
		int pre = -1;
		helper(result, target, candidates, set, candidates.size() - 1, pre);
		return result;
	}

	void helper(vector<vector<int> >& result, int target, vector<int>& candidates, vector<int>& cur, int start, int& pre)
	{
		if (target < 0) { return; }
		else if (target == 0) { result.push_back(cur); }
		else
		{
			for (int i = start; i >= 0; i--)
			{
				if (candidates[i] == pre) { continue; }
				cur.push_back(candidates[i]);
				helper(result, target - candidates[i], candidates, cur, i - 1, pre);
				pre = cur.back();
				cur.pop_back();
			}
		}
	}
};

int main(void)
{
	int nums[] = {10,1,2,7,6,1,5, 8, 8};
	vector<int> vec(nums, nums + sizeof(nums) / sizeof(nums[0]));
	Solution s;
	vector<vector<int> > ret = s.combinationSum2(vec, 8);
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