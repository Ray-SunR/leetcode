/*
Given a digit string, return all possible letter combinations 
that the number could represent.

A mapping of digit to letters (just like on the telephone buttons)
 is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer 
could be in any order you want.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		static const char* kNumPad[] = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> ret;
		if (digits.empty()) { return ret; }
		ret.push_back("");
		for (int i = 0; i < digits.size(); i++)
		{
			char c = digits[i];
			if (c == '0' || c == '1') { ret.clear(); break; }
			const char* chars = kNumPad[c - '1'];
			int size = strlen(chars);
			int oldsize = ret.size();
			for (int j = 0; j < oldsize; j++)
			{
				for (int k = 0; k < size; k++)
				{
					char cc = chars[k];
					string val = ret[j];
					val.push_back(cc);
					ret.push_back(val);
				}
			}
			ret = vector<string>(ret.begin() + oldsize, ret.end());
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<string> ret = s.letterCombinations("");
	for (int i = 0;i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}