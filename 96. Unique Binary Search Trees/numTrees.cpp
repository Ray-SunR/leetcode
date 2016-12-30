/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3

 1			2
	\ 	 /
	 2  1
*/

#include <iostream>

using namespace std;

class Solution {
public:

	int numTrees(int n) 
	{
		int ret[n + 1];
		ret[0] = ret[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			ret[i] = 0;
			for (int j = 1; j <= i; j++)
			{
				ret[i] += ret[j - 1] * ret[i - j];
			}
		}
		return ret[n];
	}
};

int main(void)
{
	Solution s;
	cout << s.numTrees(1) << endl;
	cout << s.numTrees(3) << endl;
	cout << s.numTrees(3) << endl;
	cout << s.numTrees(4) << endl;
	return 0;
}