#include <iostream>
#include <vector>

using namespace std;

#define trn_int_min 0xffffffffffffffff
#define trn_int_max 0x7fffffffffffffff
class Solution {
public:
    double findMedianSortedArrays(const vector<int>& v1, const vector<int>& v2) 
    {
        int size1 = v1.size();
        int size2 = v2.size();
        if (size2 < size1) { return findMedianSortedArrays(v2, v1); }

        int low = 0; int high = size1 * 2;
        while (low <= high)
        {
            int cut1 = low + (high - low) / 2;
            int cut2 = size1 + size2 - cut1;

            int l1 = (cut1 == 0 ? INT_MIN : v1[(cut1 - 1) / 2]);
            int r1 = (cut1 == 2 * size1 ? INT_MAX : v1[cut1 / 2]);
            int l2 = (cut2 == 0 ? INT_MIN : v2[(cut2 - 1) / 2]);
            int r2 = (cut2 == 2 * size2 ? INT_MAX : v2[cut2 / 2]);

            if (l1 > r2)
            {
                // go left in v1
                high = cut1 - 1;
            }
            else if (l2 > r1)
            {
                // go right in v1
                low = cut1 + 1;
            }
            else 
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }

        // Impossible
        return -1;
    }

private:

    int max(int val1, int val2)
    {
        return val1 > val2 ? val1 : val2;
    }

    int min(int val1, int val2)
    {
        return val1 < val2 ? val1 : val2;
    }
    void Print(const vector<int>& vec)
    {
        for (int i = 0;i < vec.size(); i++)
        {
            cout << vec[i] << " " << endl;
        }

        cout << endl;
    }
};

int main(void)
{
    //cout << (int)trn_int_max << endl;
    //cout << (int)trn_int_min << endl;
    vector<int> v1;
    vector<int> v2;
    v1.push_back(2);

    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(4);
    Solution s;
    cout << "Result is: " << s.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}
