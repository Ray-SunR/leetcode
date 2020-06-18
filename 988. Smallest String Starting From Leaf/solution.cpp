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
    string smallestFromLeaf(TreeNode* root) {
        vector<string> strings;
        priority_queue<string, vector<string>, greater<string>> pq;
        helper(root, pq, "");
        return pq.top();
    }
    
    void helper(TreeNode* root, priority_queue<string, vector<string>, greater<string>>& pq, string s) {
        if (!root) { return; }
        s.push_back('a' + root->val);
        if (!root->left && !root->right) { std::reverse(s.begin(), s.end()); pq.push(s); return; }
        helper(root->left, pq, s);
        helper(root->right, pq, s);
    }
};
