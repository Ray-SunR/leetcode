class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int result = INT_MIN;
        while (i < nums.size()) {
            if (i + 1 < nums.size() && abs(nums[i] - nums[i + 1]) > result) {
                result = abs(nums[i] - nums[i + 1]);
            }
            i++;
        }
        return result;
    }
};
