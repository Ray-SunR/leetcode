#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val, TreeNode* left = NULL, TreeNode* right = NULL)
	: val(val)
	, left(left)
	, right(right){}
	~TreeNode() { if (left) delete left; if (right) delete right; }
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return isSymmetricHelper(root, root);
	}

private:
	bool isSymmetricHelper(TreeNode* left, TreeNode* right)
	{
		if (left == right && left == NULL) { return true; }
		if (left && !right || !left && right) { return false; }
		if (left->val != right->val) { return false; }
		return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
	}
};