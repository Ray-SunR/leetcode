/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* left = NULL, TreeNode* right = NULL) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) { return true; }
		if ((root->left && (root->left->val >= root->val)) || 
			(root->right && (root->right->val <= root->val)))
		{
			return false;
		}

		TreeNode* left = root->left;
		while (left && left->right) { left = left->right; }

		TreeNode* right = root->right;
		while (right && right->left) { right = right->left; }

		if ((left && left->val >= root->val) || (right && right->val <= root->val))
		{
			return false;
		}
		else
		{
			return isValidBST(root->left) && isValidBST(root->right);
		}
	}
};

int main(void)
{
	TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1, NULL, NULL), new TreeNode(3, NULL, NULL)), new TreeNode(5, NULL, NULL));
	TreeNode* root1 = new TreeNode(1, new TreeNode(1, NULL, NULL), NULL);
	Solution s;
	cout << s.isValidBST(root1) << endl;
}