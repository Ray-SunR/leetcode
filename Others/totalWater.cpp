#include <iostream>
#include <vector>

using namespace std;

// 1 0 4 8 7 4 0 3 1
int TotalWater(vector<int>& water)
{
	//cout << "here" << endl;
	int low = 0;
	int high = water.size() - 1;
	int ret = 0;
	int curmax = INT_MIN;
	while (low <= high)
	{
		//cout << "low: " << low << " high: " << high << endl;
		if (water[low] < water[high])
		{
			if (water[low] > curmax)
			{
				curmax = water[low];
			}
			else
			{
				ret += curmax - water[low];
			}
			low++;
		}
		else
		{
			if (water[high] > curmax)
			{
				curmax = water[high];
			}
			else
			{
				ret += curmax - water[high];
			}
			high--;
		}
	}
	return ret;
}

int main(void)
{
	int water[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> vec(water, water + sizeof(water) / sizeof(water[0]));
	cout << TotalWater(vec) << endl;
	return 0;
}