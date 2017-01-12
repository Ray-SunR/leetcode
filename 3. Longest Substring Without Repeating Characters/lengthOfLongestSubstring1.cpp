#include <iostream>
#include <map>

using namespace std;
// abcabcbb 
// abc
class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		map<int, int> hash;
		int left = 0; int right = 0; int max = 0;
		while (right < s.size())
		{
			if (hash.find(s[right]) != hash.end())
			{
				int pos = hash[s[right]];
				max = right - left > max ? right - left : max;
				left = left < pos + 1 ? pos + 1 : left;
			}
			hash[s[right]] = right;
			right++;
		}
		return right - left > max ? right - left : max;
	}
};

int main(void)
{
	Solution s;
	cout << s.lengthOfLongestSubstring("abbaaa") << endl;
	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << s.lengthOfLongestSubstring("bbbbb") << endl;
	cout << s.lengthOfLongestSubstring("") << endl;
	cout << s.lengthOfLongestSubstring("abcdef") << endl;
	cout << s.lengthOfLongestSubstring("aabacdebaaabbb") << endl;
	return 0;
}