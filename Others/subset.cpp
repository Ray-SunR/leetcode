// Generate subsets of a set
// eg. { a, b. c} => {{}, {a}, {b}, {c}, {ab}, {bc}, {ac}, {abc}}

// Key: treat is a binary numbers, e.g we have {a, b, c} which has a size of 3, then 
// we know the total number subsets is 8 (2 ^ 3). Then, we basically need to output
// all numbers from 0 ~ 2^n - 1. and place one with corresponding character.
#include <iostream>
#include <vector>
using namespace std;

vector<string> Subsets(const string& str)
{
	cout << str << endl;
	vector<string> ret;
	int size = str.size();
	int max = (1 << size) - 1;
	for (int i = 0;i <= max; i++)
	{
		string toadd;
		int count =  0;
		int num = i;
		while (count < str.size())
		{
			if (num & 1)
			{
				toadd.push_back(str[count]);
			}
			num >>= 1;
			count++;
		}
		ret.push_back(toadd);
	}
	return ret;
}

int main(void)
{
	string str = "abcd";
	vector<string> numbers = Subsets(str);
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}
	return 0;
}