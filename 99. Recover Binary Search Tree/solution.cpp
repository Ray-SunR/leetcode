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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> order;
        inOrder(order, root);
        int begin = 0;
        int end = order.size() - 1;
        int targetIndex1 = -1;
        int targetIndex2 = -1;
        while (begin < order.size()) {
            if (begin + 1 < order.size() && order[begin + 1]->val < order[begin]->val) {
                targetIndex1 = begin;
                break;
            }
            begin++;
        }
        
        while (end >= 0) {
            if (end - 1 >= 0 && order[end - 1]->val > order[end]->val) {
                targetIndex2 = end;
                break;
            }
            end--;
        }

        int temp = order[targetIndex1]->val;
        order[targetIndex1]->val = order[targetIndex2]->val;
        order[targetIndex2]->val = temp;
    }
    
    void inOrder(vector<TreeNode*>& order, TreeNode* root) {
        if (!root) { return; }
        inOrder(order, root->left);
        order.push_back(root);
        inOrder(order, root->right);
    }
};
