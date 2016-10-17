/*
Given n non-negative integers a1, a2, ..., an, 
where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints 
 of line i is at (i, ai) and (i, 0). Find two lines, 
 which together with x-axis forms a container, 
 such that the container contains the most water.
*/
 /*	 
 	 |	 | 
	 |	 | 
	 | | | 
 | | | | 
 | | | | 
 | | | | |
 ---------
 */

 // Thoughts:
 /*
 - Start from both begin and end. Calculate the area between that. 
- If there exists area larger than that, they must be higher than one of the begin and end value.
- Then we keep two pointers, one goes from left to right, one goes from right to left.
- ptr1 stops as soon as its own value is greater than ptr2 or its value is smaller than begin and end value.
- Once ptr1 stops and its value is smaller than ptr2, we start calcuating the area from begin to ptr1, ptr1 to end, ptr1 and ptr2.
- Once ptr2 stops and its value is smaller than ptr1, we start caculating the area from begin to ptr2, ptr2 to end, ptr1 and ptr2.
- ptr1 and ptr2 only advance by one if their value is smaller than each other because we don't want to skip big values!

`while (i < j && a[i] <= a[j] && a[i] < min(a[low], a[high])) { i++; }` -> skip everything if value pointed by i is smaller than all of low and high.
`while (i < j && a[j] <= a[i] && a[j] < min(a[low], a[high])) { j--; }` -> skip verything if value pointed by j is samller than all of low and high
 */
#include <iostream>
#include <vector>

 using namespace std;
 class Solution {
 public:
 	int maxArea(const vector<int>& a) {
 		int low = 0; int high = a.size() - 1;
 		int ret = (high - low) * min(a[low], a[high]);
 		int i = low; int j = high;
 		while (i < j)
 		{
 			while (i < j && a[i] <= a[j] && a[i] < min(a[low], a[high])) { i++; }
 			if (i < j && a[i] <= a[j])
 			{
 				ret = max(ret, (i - low) * min(a[i], a[low]));
 				ret = max(ret, (high - i) * min(a[i], a[high]));
 				ret = max(ret, (j - i) * min(a[i], a[j]));
 				i++;
 			}
 			while (i < j && a[j] <= a[i] && a[j] < min(a[low], a[high])) { j--; }
 			if (i < j && a[j] <= a[i])
 			{
 				ret = max(ret, (high - j) * min(a[j], a[high]));
 				ret = max(ret, (j - low) * min(a[j], a[low]));
 				ret = max(ret, (j - i) * min(a[i], a[j]));
 				j--;
 			}
 		}

 		return ret;
 	}

 	int max(int v1, int v2)
 	{
 		return v1 > v2 ? v1 : v2;
 	}

 	int min(int v1, int v2)
 	{
 		return v1 < v2 ? v1 : v2;
 	}
 };

 int main(void)
 {
 	vector<int> a;
 	a.push_back(10);
 	a.push_back(9);
 	a.push_back(8);
 	a.push_back(7);
 	a.push_back(6);
 	a.push_back(5);
 	a.push_back(4);
 	a.push_back(3);
 	a.push_back(2);
 	a.push_back(1);

 	vector<int> b;
 	b.push_back(1);
 	b.push_back(1);
 	Solution s;
 	cout << s.maxArea(b) << endl; 
 	return 0;
 }