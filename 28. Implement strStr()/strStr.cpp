/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
*/

#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(const string& haystack, const string& needle) {
		size_t pos = haystack.find(needle);
		return pos == string::npos ? -1 : pos;
	}
};

int main(void)
{
	Solution s;
	cout << s.strStr("abcdefgh","f");
	return 0;
}