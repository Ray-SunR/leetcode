/*
Write a function to find the longest common
 prefix string amongst an array of strings.
*/

#include <iostream>
#include <vector>

 using namespace std;

 class Solution {
 public:
 	string longestCommonPrefix(const vector<string>& strs) {
 		if (strs.empty()) { return ""; }
 		string ret = strs[0];
 		for (int i = 1; i < strs.size(); i++)
 		{
 			while (strs[i].find(ret) != 0)
 			{
 				ret = ret.substr(0, ret.size() - 1);
 				if (ret.empty()) { return ret; }
 			}
 		}

 		return ret;
 	}
 };

 int main(void)
 {
 	const char* kStrs[] = { "c", "ccc", "cccc"};
 	vector<string> strs(kStrs, kStrs + 3);
 	Solution s;
 	cout << s.longestCommonPrefix(strs) << endl;
 	return 0;
 }