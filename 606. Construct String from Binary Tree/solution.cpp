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
    string tree2str(TreeNode* t) {
        string result;
        helper(t, result);
        return result;
        // return result.substr(1, result.size() - 1);
    }
    
    void helper(TreeNode* t, string& s) {
        if (!t) { 
            return; 
        }
        
        s += std::to_string(t->val);
        if (!t->left && !t->right) {
            return;
        }
        
        if (t->left) {
            s += "(";
            helper(t->left, s);
            s += ")";
        } else if (t->right) {
            s += "()"; 
        }
        
        if (t->right) {
            s += "(";
            helper(t->right, s);
            s += ")";
        }
    }
};
