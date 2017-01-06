#include <iostream>

using namespace std;

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

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
	int minDepth(TreeNode* root) {
		if (!root) { return 0; }
		int mind = INT_MAX;
		helper(root, mind, 0);
		return mind;
	}

	void helper(TreeNode* root, int& mind, int depth)
	{
		if (!root) 
		{
			return;
		}
		depth++;
		helper(root->left, mind, depth);
		helper(root->right, mind, depth);

		// leaf
		if (!root->left && !root->right)
		{
			mind = min(mind, depth);
		}
	}
private:
	int min(int a, int b)
	{
		return a < b ? a : b;
	}
};

int main(void)
{
	TreeNode* root = new TreeNode(4, new TreeNode(3, new TreeNode(2, NULL, NULL), new TreeNode(5, NULL, NULL)), new TreeNode(6, NULL, NULL));
	Solution s;
	cout << "min: " << s.minDepth(root) << endl;
	cout << "min: " << s.minDepth(new TreeNode(1, NULL, NULL)) << endl;
	return 0;
}