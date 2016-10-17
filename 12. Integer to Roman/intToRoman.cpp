/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>

using namespace std;

// 1, 2, 3, 4, 5, 6, 7, 8, 9
const char* kRomansSingle[] = { "I", "II", "III", "IV", 
"V", "VI", "VII", "VIII", "IX"};

// 10, 20, 30, 40, 50, 60, 70, 80, 90
const char* kRomanTens[] = { "X", "XX", "XXX", "XL", "L",
"LX", "LXX", "LXXX", "XC"};

//100, 200, 300, 400, 500, 600, 700, 800, 900
const char* kRomanHundres[] = {"C", "CC", "CCC", "CD", "D",
"DC", "DCC", "DCCC", "CM"};

//1000, 2000, 3000
const char* kRomanThousands[] = {"M", "MM", "MMM"};

// clxxvi
class Solution {
public:
	string intToRoman(int num) {
		string ret = "";
		int magnitude = 1;
		while (num)
		{
			int remainder = num % 10;
			if (remainder)
			{
				switch(magnitude)
				{
					case 1:
					ret = kRomansSingle[remainder - 1] + ret;
					break;
					case 10:
					ret = kRomanTens[remainder - 1] + ret;
					break;
					case 100:
					ret = kRomanHundres[remainder - 1] + ret;
					break;
					case 1000:
					ret = kRomanThousands[remainder - 1] + ret;
					break;
					default:
					return "";
					break;
				//unexpected
				}
			}
			
			magnitude *= 10;
			num /= 10;
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	for (int i = 1; i < 4000; i++)
	{
		cout << i << ": " << s.intToRoman(i) << endl;
	}
	return 0;
}