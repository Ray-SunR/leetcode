/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

#include <iostream>

using namespace std;

// 12455421
// 1221
// 121
// 101
class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x == 0) { return true; }
		if (x < 0 || x % 10 == 0) { return false; }
		int backsum = 0;
		while (x)
		{
			backsum = backsum * 10 + x % 10;
			if (backsum == x || (x >= 10 && x / 10 == backsum))
			{
				return true;
			}
			x /= 10;
		}
		return false;
	}
};

int main(void)
{
	int a = 12344321;
	int b = 1221;
	int c = -1001;
	int d = 123312;
	Solution S;
	cout << a << " : " << S.isPalindrome(a) << endl;
	cout << b << " : " << S.isPalindrome(b) << endl;
	cout << c << " : " << S.isPalindrome(c) << endl;
	cout << d << " : " << S.isPalindrome(d) << endl;
	return 0;
}