class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int from = 0; int result = INT_MAX; int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                result = min(result, i - from + 1);
                sum -= nums[from++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
