#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:

	int mostWater(vector<int>& water)
	{
		int most = 0;
		int i = 0; int j = water.size() - 1;
		while (i < j)
		{
			int min = water[i] < water[j] ? water[i] : water[j];
			if (most < (j - i) * min)
			{
				most = (j - i) * min;
			}

			while (i < j && water[i] <= min) { i++; }
			while (i < j && water[j] <= min) { j--; }
		}
		return most;
	}

	int trapWater(vector<int>& water)
	{
		int lm = 0;
		int rm = 0;
		int i = 0;
		int j = water.size() - 1;
		int total = 0;
		while (i <= j)
		{	
			if (water[i] < water[j])
			{
				if (water[i] > lm) 
				{
					lm = water[i];
				}
				total += lm - water[i];
				i++;
			}
			else
			{
				if (water[j] > rm)
				{
					rm = water[j];
				}
				total += rm - water[j];
				j--;
			}
		}
		return total;
	}
	// https://abitofcs.blogspot.ca/2014/11/data-structure-sliding-window-minimum.html
	vector<int> maxSlidingWindow(vector<int>& nums, int k) 
	{
		deque<int> q;
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!q.empty() && i - q.front() == k) { q.pop_front(); }
			while (!q.empty() && nums[q.back()] < nums[i])
			{
				q.pop_back();
			}
			q.push_back(i);
			if (i >= k - 1) { ret.push_back(nums[q.front()]); }
		}
		return ret;
	}

	// nlogn
	vector<int> maxSlidingWindow1(vector<int>& nums, int k)
	{
		// (val, pos)
		priority_queue<pair<int, int> > q;
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			 while (!q.empty() && q.top().second <= i - k) { q.pop(); }
			 q.push(pair<int, int>(nums[i], i));
			 if (i >= k - 1) { ret.push_back(q.top().first); }
		}
		return ret;
	}

	// nlogk
	vector<int> maxSlidingWindow2(vector<int>& nums, int k)
	{
		multiset<int> q;
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			if (q.size() == k) { q.erase(q.find(nums[i - k])); }
			q.insert(nums[i]);
			if (i >= k - 1) { ret.push_back(*q.rbegin()); }
		}
		return ret;
	}
};

int main(void)
{
	int water[] = { 0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> watervec(water, water + sizeof(water) / sizeof(water[0]));

	int nums[] = {1,3,-1,-3,5,3,6,7};
	vector<int> vec(nums, nums + sizeof(nums) / sizeof(nums[0]));
	Solution s;
	vector<int> ret = s.maxSlidingWindow2(vec, 3);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;

	cout << s.mostWater(watervec);
	return 0;
}

