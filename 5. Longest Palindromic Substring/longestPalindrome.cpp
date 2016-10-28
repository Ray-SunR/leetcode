/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there
exists one unique longest palindromic substring.
*/

#include <iostream>
using namespace std;
// # a # b # b # a #
// 0 1 2 3 4 5 6 7 8

// # a # b # a #
// 0 1 2 3 4 5 6

// For a string of n size -> 2 * n + 1 positions -> 2 * n indices. 
// The benefit is to neglect odd/even since we want to expand the 
// palindrome from 'center'. 

// n left right
// 1  0			0
// 2	0			1
// 3	1 	  1 		=> left = (n - 1) / 2; right = n / 2
// 4 	1 		2
// 5  2			2

// Thoughts, traverse from left to right, try expanding palindrome 
// as much as possible. 
class Solution
{
public:
	string longestPalindrome(const string& s)
	{
		string ret = "";
		for (int i = 1; i <= 2 * s.size() - 1; i++)
		{
			int left = (i - 1) / 2;
			int right = i / 2;
			string temp = expandPalindrome(s, left, right);
			if (temp.size() > ret.size()) 
			{
				ret = temp;
			}
		}
		return ret;
	}

	string expandPalindrome(const string& s, int left, int right)
	{
		string ret;
		while (left >= 0 && right < s.size() && s[left] == s[right]) 
		{
			left--;
			right++;
		}
		left++;
		return s.substr(left, right - left);
	}
};

int main(void)
{
	Solution s;
	cout << s.longestPalindrome("aaabbbaabbbbabbbbbbbbbbbbaaaaaa") << endl;
	return 0;
}