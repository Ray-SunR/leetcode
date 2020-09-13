class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prods = vector<int>(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            prods[i] = prods[i - 1] * nums[i - 1];
        }
        
        for (int j = nums.size() - 1, m = 1; j >=0; j--) {
            prods[j] = prods[j] * m;
            m *= nums[j];
        }
        
        return prods;
    }
};
