class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        int result = 1;
        int index = 0;
        while (index < nums.size()) {
            int count = 1;
            while (index + 1 < nums.size() && nums[index + 1] > nums[index]) { 
                count++; 
                result = max(result, count);
                index++; 
            }
            
            index++;
        }
        return result;
    }
};
