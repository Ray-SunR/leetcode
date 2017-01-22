#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) { return 1; }
		bool neg = n < 0 ? true : false;
		n = n < 0 ? -n : n;
		double ret = 1;
		while (n)
		{
			if (n & 1) { ret *= x; }
			x *= x;
			n /= 2;
		}
		return neg ? 1.0 / ret : ret;
	}
};

int main(void)
{
	return 0;
}