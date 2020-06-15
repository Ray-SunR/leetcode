class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1;
        int pos2 = n - 1;
        int ret_pos = m + n - 1;
        
        while (ret_pos >= 0 && pos1 >= 0 && pos2 >= 0) {
            // cout << "pos1: " << pos1 << " pos2: " << pos2 << " ret_pos: " << ret_pos << endl;
            if (nums1[pos1] > nums2[pos2]) {
                nums1[ret_pos] = nums1[pos1--];
            } else {
                nums1[ret_pos] = nums2[pos2--];
            }
            ret_pos--;
        }
        
        while (pos2 >= 0) {
            nums1[ret_pos--] = nums2[pos2--];
        }
    }
};
