#include <iostream>

using namespace std;
class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		while (x){
			int part = x % 10;
			int newval = ret * 10 + part;
			if ((newval - part) / 10 != ret) { return 0; }
			ret = newval;
			x /= 10;
		}
		return ret;
	}
};

int main(void)
{
	int val = 1;
	Solution s;
	cout << s.reverse(val) << endl;
	return 0;
}