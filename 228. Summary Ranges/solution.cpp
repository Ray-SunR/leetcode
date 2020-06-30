class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() == 0) {
            return ret;
        }
        
        int i = 1;
        int begin = nums[0];
        while (i < nums.size()) {
            if (nums[i - 1] + 1 != nums[i]) {
                if (nums[i - 1] != begin) {
                    ret.push_back(to_string(begin) + "->" + to_string(nums[i - 1]));
                } else {
                    ret.push_back(to_string(begin));
                }
                
                begin = nums[i];
            }
            ++i;
        }
        
        if (nums[nums.size() - 1] != begin) {
            ret.push_back(to_string(begin) + "->" + to_string(nums[nums.size() - 1]));
        } else {
            ret.push_back(to_string(nums[nums.size() - 1]));
        }
        return ret;
    }
    
};
