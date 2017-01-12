#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) 
	{
		vector<int> ret;
		vector<int> hash(256, 0);
		// Initialize hash
		for (int i = 0; i < p.size(); i++) { hash[p[i]]++; }
		int left = 0; int right = 0; int count = p.size();
		while (right < s.size())
		{
			if (--hash[s[right++]] >= 0) { count--; }
			if (count == 0) { ret.push_back(left); }
			if (right - left == p.size() && ++hash[s[left++]] >= 1) { count++; }
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<int> ret = s.findAnagrams("abab", "ab");
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";	
	}
	cout << endl;
	return 0;
}