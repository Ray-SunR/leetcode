/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

// 13 / 3
// 3 -> 6 -> 12 -> 24
// 1 -> 2 -> 4	-> 8
//  |
//  V	
// 12 -> 15
// 4 	-> 5
#include <iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
		{
			return INT_MAX;
		}
		bool neg = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? true : false;
		long long ldividend = labs((long long)dividend);
		long long ldivisor = labs((long long)divisor);
		if (ldividend < ldivisor) { return 0; }
		long long tmp = ldivisor;
		long long ret = 1;
		while (tmp < ldividend)
		{
			tmp <<= 2; ret <<= 2;
		}
		if (tmp == ldividend) { return neg ? -ret : ret; }
		tmp >>= 2; ret >>= 2;
		return neg ? -(ret + divide(ldividend - tmp, ldivisor)) : (ret + divide(ldividend - tmp, ldivisor));
	}

	int divide1(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
		{
			return INT_MAX;
		}
		bool neg = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? true : false;
		long long ldividend = labs((long long)dividend);
		long long ldivisor = labs((long long)divisor);
		if (ldividend < ldivisor) { return 0; }
		long long ret = 0;
		while (ldividend >= ldivisor)
		{
			long long tmp = ldivisor;
			long long tempret = 1;
			while (tmp <= ldividend)
			{
				tmp <<= 2; tempret <<= 2;
			}
			if (tmp == ldividend) { return neg ? -ret : ret; }
			tmp >>= 2; tempret >>= 2;
			ldividend -= tmp;
			ret += tempret;
		}
		return neg ? -ret : ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.divide(INT_MAX, 1) << endl;
	return 0;
}