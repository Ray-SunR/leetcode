/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
between two nodes v and w as the lowest node in T that has both v and w as descendants 
(where we allow a node to be a descendant of itself).”
*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* left = NULL, TreeNode* right = NULL) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root || root == p || root == q) { return root; }
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return left && right ? root : (left ? left : right);
	}
};

int main(void)
{
	TreeNode* p = new TreeNode(7, NULL, NULL);
	TreeNode* q = new TreeNode(8, NULL, NULL);
	TreeNode* root = 
	new TreeNode(3,
		new TreeNode(5,
			new TreeNode(6, NULL, NULL),
			new TreeNode(2,
				p,
				new TreeNode(4, NULL, NULL))),
		new TreeNode(1, 
			new TreeNode(0, NULL, NULL),
			q));

	Solution s;
	TreeNode* head = s.lowestCommonAncestor(root, p, q);
	cout << "lca: " << head->val << endl;
	return 0;
}