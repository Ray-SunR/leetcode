/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string ret = "1";
		while (n > 1)
		{
			int pos = 0;
			string newret = "";
			while (pos < ret.size())
			{
				int count = 1;
				while (pos + 1 < ret.size() && ret[pos + 1] == ret[pos]) { pos++; count++; }
				stringstream ss; ss << count;
				string part = ss.str();
				newret += part;
				newret.push_back(ret[pos]);
				cout << "part: " << part << endl;
				pos++;
			}
			cout << "newret: " << newret << endl;
			ret = newret;
			n--;
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.countAndSay(10) << endl;
	return 0;
}