#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ret;
		if (n == 0) { ret.push_back(0); return ret; }
		vector<int> pre = grayCode(n - 1);
		ret.insert(ret.begin(), pre.begin(), pre.end());
		for (int i = pre.size() - 1; i >=0 ; i--)
		{
			ret.push_back(1 << (n - 1) | pre[i]);
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	for (int i = 0; i <= 10; i++)
	{
		vector<int> ret = s.grayCode(i);
		for (int j = 0; j < ret.size(); j++)
		{
			cout << std::bitset<32>(ret[j]) << endl; 
		}
		cout << "------" << endl;
	}
	return 0;
}