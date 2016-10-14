/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there
 exists one unique longest palindromic substring.
*/

#include <iostream>

 using namespace std;

 class Solution {
 public:
 	string longestPalindrome(string s) {
 		if (IsPalindrome(s, 0, s.size() - 1))
 		{
 			return s;
 		}
 		int ptr_start = 0;
 		int ptr_end = 0;
 		int max_length = 0;
 		int max_start = 0;
 		int max_end = 0;
 		while (ptr_start < s.size())
 		{
 			ptr_end = ptr_start;
 			while (ptr_end < s.size())
 			{
 				// Find a position where it's equal to the start element
 				while (ptr_end < s.size() && s[ptr_end] != s[ptr_start]) 
 				{
 					ptr_end++;
 				}

 				if (ptr_end >= s.size()) { break; }

 				if (IsPalindrome(s, ptr_start, ptr_end))
 				{
 					if (ptr_end - ptr_start + 1 > max_length)
 					{
 						max_start = ptr_start;
 						max_end = ptr_end;
 						max_length = ptr_end - ptr_start + 1;
 					}
 				}
 				ptr_end++;
 			}
 			ptr_start++;
 		}

 		return string(s.begin() + max_start, s.begin() + max_end + 1);
 	}

 	string expandPalindrome(const string& s, int& l, int& r)
 	{
 		while (l >= 0 && r < s.size() && s[l] == s[r])
 		{
 			l--;
 			r++;
 		}

 		l++;
 		return s.substr(l, r - l);
 	}

 	// # 1 # 2 # 3 #
 	string longestPalindrome1(const string& s)
 	{
 		int max_length = 0;
 		int max_start = 0;
 		int max_end = 0;
 		for (int i = 1; i <= 2 * s.size() - 1; i++)
 		{
 			int l = (i - 1) / 2;
 			int r = i / 2;
 			string found = expandPalindrome(s, l, r);
 			if (found.size() > max_end - max_start)
 			{
 				max_start = l;
 				max_end = r;
 			}
 		}

 		return s.substr(max_start, max_end - max_start);
 	}

 	bool IsPalindrome(const string& s, int start, int end)
 	{
 		if (s.empty() || s.size() == 1) { return true; }

 		while (start < end)
 		{
 			if (s[start] == s[end])
 			{
 				start++;
 				end--;
 			}
 			else
 			{
 				return false;
 			}
 		}

 		return true;
 	}
 };

 int main(void)
 {
 	string s = "aaaaabbaaaaacde";
 	Solution solution;
 	cout << "Longest: " << solution.longestPalindrome1(s) << endl;
 	return 0;
 }