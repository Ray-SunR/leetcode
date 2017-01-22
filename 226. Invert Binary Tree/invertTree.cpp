#include <iostream>
#include <vector>

using namespace std;

/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
	TreeNode* invertTree(TreeNode* root) 
	{
		if (!root) { return NULL; }
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		root->left = right;
		root->right = left;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}

		void levelOrderTraversal(TreeNode* root, int level, vector<int>& ret)
	{
		if (!root) { return; }
		if (level == 1) 
		{ 
			ret.push_back(root->val); 
			return; 
		}
		levelOrderTraversal(root->left, level - 1, ret);
		levelOrderTraversal(root->right, level - 1, ret);
	}

	int height(TreeNode* root)
	{
		if (!root) { return 0; }
		return max(1 + height(root->left), 1 + height(root->right));
	}

	void levelOrderTraversal(TreeNode* root)
	{
		int ht = height(root);
		for (int i = 1; i <= ht; i++)
		{
			std::vector<int> ret;
			levelOrderTraversal(root, i, ret);
			for (int j = 0; j < ret.size(); j++)
			{
				cout << ret[j] << " ";
			}
			cout << endl;
		}
	}
};

int main(void)
{
	TreeNode* root = new TreeNode(3, 
		new TreeNode(9, NULL, NULL), 
		new TreeNode(20, 
			new TreeNode(15, NULL, NULL),
			new TreeNode(7, NULL, NULL)));
	Solution s;
	s.levelOrderTraversal(root);

	root = s.invertTree(root);
	s.levelOrderTraversal(root);
	return 0;
}