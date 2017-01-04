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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == q) { return true; }
		if (p && !q || !p && q) { return false; }
		if (p->val != q->val) { return false; }
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

