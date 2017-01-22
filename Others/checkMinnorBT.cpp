#include <iostream>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left; TreeNode* right;
	TreeNode(int val, TreeNode* left, TreeNode* right)
	: val(val)
	, left(left)
	, right(right) {}
};

bool IsMirrorBT(TreeNode* left, TreeNode* right)
{
	if (!left && !right) { return true; }
	if ((left && !right) || (!left && right)) { return false; }
	return left->val == right->val && IsMirrorBT(left->left, right->right) && IsMirrorBT(left->right, right->left);
}

int main(void)
{
	TreeNode* root = new TreeNode(1, 
		new TreeNode(2, new TreeNode(3, NULL, NULL), new TreeNode(4, new TreeNode(5, NULL, NULL), NULL)),
		new TreeNode(2, new TreeNode(4, NULL, new TreeNode(5, NULL, NULL)), new TreeNode(3, NULL, NULL)));
	if (IsMirrorBT(root, root))
	{
		cout << "yes" << endl;
	}
	return 0;
}