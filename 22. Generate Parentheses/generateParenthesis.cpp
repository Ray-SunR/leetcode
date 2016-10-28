/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

// Thoughts: set two counters one for each for '(' and ')'. If the counter
// for '(' is less than the 'n' then keep dumping '(' in the ret set. 
// the recursive exit condition is when the right counter hit n. 
// keep dumping ')' into the result set if the right is less than left

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> ret;
		helper(ret, n, "", 0, 0);
		return ret;
	}

	void helper(vector<string>& ret, int n, string s, int left, int right)
	{
		if (right == n)
		{
			ret.push_back(s);
			return;
		}
		if (left < n)
		{
			helper(ret, n, s + "(", left + 1, right);
		}

		if (right < left)
		{
			helper(ret, n, s + ")", left, right + 1);
		}
	}
};

int main(void)
{
	Solution s;
	vector<string> ret = s.generateParenthesis(3);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
	return 0;
}