#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
using namespace std;

class Solution {
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs) 
	{
		map<std::string, vector<string> > hash;
		vector<vector<string> > ret;
		for (int i = 0; i < strs.size(); i++)
		{
			string s = strs[i];
			std::sort(s.begin(), s.end());
			hash[s].push_back(strs[i]);
		}
		map<std::string, vector<string> >::const_iterator it = hash.begin(); 
		while (it != hash.end())
		{
			ret.push_back(it->second);
			++it;
		}
		return ret;
	}
};

int main(void)
{
	std::string strs[] = { "eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> vec(strs, strs + sizeof(strs) / sizeof(strs[0]));
	Solution s;
	vector<vector<string> >  ret = s.groupAnagrams(vec);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
