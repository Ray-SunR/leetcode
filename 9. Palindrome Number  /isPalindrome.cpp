#include <iostream>

using namespace std;

// 123454321
// 1221
// 2147483647
// 10
class Solution {
public:
	bool isPalindrome(int x) {
		if (x == 0) { return true; }
		if (x % 10 == 0) { return false; }

		int back = 0;
		while (x > 0)
		{
			back = back * 10 + x % 10;
			if (back == x || 
				(x >= 10 && back == x / 10) ||
				(x >= 100 && back == x / 100))
			{
				return true;
			}
			else
			{
				x = x / 10;
			}
		}
		return false;
	}
};

int main(void)
{
	Solution s;
	cout << s.isPalindrome(1234) << endl;
	cout << s.isPalindrome(123454321) << endl;
	cout << s.isPalindrome(2147447412) << endl;
	return 0;
}