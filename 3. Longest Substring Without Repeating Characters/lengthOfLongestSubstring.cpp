/*
Given a string, find the length of the longest substring without 
repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note 
that the answer must be a substring, "pwke" is a subsequence and 
not a substring.
*/

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		map<char, int> hash;
		int max_length = 0;
		for (int i = 0, j = 0;i < s.size(); i++)
		{
			map<char, int>::const_iterator it = hash.find(s[i]);
			if (it != hash.end())
			{
				// move j to the right of the duplicated char found
				j = j > it->second + 1? j : it->second + 1;
			}

			hash[s[i]] = i;
			max_length = max_length < i - j + 1 ? i - j + 1 : max_length;
		}
		return max_length;
	}
};

int main(void)
{
	string a = "abcdefgabcdabcdefgh";
	Solution s;
	cout << s.lengthOfLongestSubstring(a) << endl;
	return 0;
}