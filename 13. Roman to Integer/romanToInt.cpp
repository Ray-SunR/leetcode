/*
Given a roman numeral, convert it to an integer.

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

//MMMCMXCIX -> 3999
// V -> 5
// X -> 10
// L -> 50
// C -> 100
// D -> 500
// M -> 1000
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

	int romanToInt(string s) {
		int ret = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			switch(s[i])
			{
				case 'I':
				ret += 1;
				break;
				case 'V':
				{
					if (i - 1 >= 0 && s[i - 1] == 'I' )
					{
						ret += 4;
						i--;
					}
					else
					{
						ret += 5;
					}
				}
				break;
				case 'X':
				{
					if (i - 1 >= 0 && s[i - 1] == 'I')
					{
						ret += 9;
						i--;
					}
					else
					{
						ret += 10;
					}
				}
				break;
				case 'L':
				{
					if (i - 1 >= 0 && s[i - 1] == 'X')
					{
						ret += 40;
						i--;
					}
					else
					{
						ret += 50;
					}
				}
				break;
				case 'C':
				{
					if (i - 1 >= 0 && s[i - 1] == 'X')
					{
						ret += 90;
						i--;
					}
					else
					{
						ret += 100;
					}
				}
				break;
				case 'D':
				{
					if (i - 1 >= 0 && s[i - 1] == 'C')
					{
						ret += 400;
						i--;
					}
					else
					{
						ret += 500;
					}
				}
				break;
				case 'M':
				{
					if (i - 1 >= 0 && s[i - 1] == 'C')
					{
						ret += 900;
						i--;
					}
					else
					{
						ret += 1000;
					}
				}
				break;
			}
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	for (int i = 1; i < 4000; i++)
	{
		cout << s.romanToInt(s.intToRoman(i)) << endl;
	}
	return 0;
}