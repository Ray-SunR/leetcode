/*
Given two numbers represented as strings, return multiplication of the numbers as a string.
*/

#include <iostream>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string ret(num1.size() + num2.size(), '0');
		for (int i = num1.size() - 1; i >= 0; i--)
		{
			for (int j = num2.size() - 1; j >= 0; j--)
			{
				//cout << "i: " << i << "j : " << j << endl;
				int num = (num1[i] - '0') * (num2[j] - '0');
				//cout << "num1[i]: " << num1[i] << " * num2[j]: " << num2[j] << " = " << num << endl;
				int pos = ret.size() - 1 - (num1.size() - 1 - i + num2.size() - 1 - j);
				//cout << "pos: " << pos << endl;
				int val = ret[pos] - '0' + num;
				//cout << "val : " << val << endl;
				while (val >= 10)
				{
					int co = val / 10;
					int rm = val % 10;
					ret[pos--] = '0' + rm;
					val = ret[pos] - '0' + co;
				}			
				//cout << "val at pos: " << pos << endl;
				ret[pos] = '0' + val;
			}
		}

		if (ret.find_first_not_of('0') == std::string::npos)
		{
			return "0";
		}
		else
		{
			return ret.substr(ret.find_first_not_of('0'));
		}
	}
};

int main(void)
{
	Solution s;
	cout << s.multiply("199293819238918491238891283", "129381298317239871298639871628937618923") << endl;
	return 0;
}