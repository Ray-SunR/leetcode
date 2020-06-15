:/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        helper(root, 0, nums);
        
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret += nums[i];
        }
        return ret;
    }
    
    void helper(TreeNode* root, int prev, vector<int>& nums) {
        if (!root) { return; }
        if (!root->left && !root->right) {
            nums.push_back(prev * 10 + root->val);
        }
        helper(root->left, prev * 10 + root->val, nums);
        helper(root->right, prev * 10 + root->val, nums);
    }
};
