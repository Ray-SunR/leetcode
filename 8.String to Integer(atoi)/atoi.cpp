#include <iostream>
#include <cstdlib>

using namespace std;

// #1 chars with no number
// #2 optionally chars with numbers (optionally a +/- sign) in between
// #3 numbers like 0000123
// #4 overflow -> returns 0
class Solution {
public:
	int myAtoi(string str) {
		int ret = 0;
		int index = 0;
		while (index < str.size() && str[index] == ' ') { index++; }

		bool neg = false;
		if (index < str.size() && (str[index] == '+' || str[index] == '-'))
		{
			neg = str[index++] == '-';
		}

		while (index < str.size() && str[index] <= '9' && str[index] >= '0')
		{
			if (INT_MAX / 10 < ret) { return neg ? INT_MIN : INT_MAX; }
			int newval = ret * 10 + str[index++] - '0';
			if (newval < ret)
			{
				return neg ? INT_MIN : INT_MAX;
			}

			ret = newval;
		}

		return neg ? -ret : ret;
	}
};

int main(void)
{
	string a = "    -9147483648";
	string b = "    absdf123afsdfa123f4fas2343";
	string c = "    - 5  12";
	string d = "absdfwe000004443232342344";
	string e = "+sdf++fasd+1234d34";
	string f = "-2hjk";

	Solution s;
	cout << s.myAtoi(a) << endl;
	cout << s.myAtoi(b) << endl;
	cout << s.myAtoi(c) << endl;
	cout << s.myAtoi(d) << endl;
	cout << s.myAtoi(e) << endl;
	cout << s.myAtoi(f) << endl;
	cout << atoi(d.c_str()) << endl;
	return 0;
}