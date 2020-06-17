/**
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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) { return 0; }
        int m = INT_MIN;
        helper(root, root, m);
        return m;
    }
    
    int helper(TreeNode* root, TreeNode* parent, int& m) {
        if (!root) { return 0; }
        
        if (root->val == parent->val && root != parent) {
            int left = helper(root->left, parent, m);
            int right = helper(root->right, parent, m);
            
            m = max(m, left + right);
            return max(left + 1, right + 1);
        } else {
            int left = helper(root->left, root, m);
            int right = helper(root->right, root, m);
            m = max(m, left + right);
            return 0;
        }
    }
};
