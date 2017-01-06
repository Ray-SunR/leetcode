#include <iostream>

using namespace std;

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
	void flatten(TreeNode* root) {
		helper(root);
	}

private:
	TreeNode* helper(TreeNode* root)
	{
		if (!root) { return NULL; }
		TreeNode* lt = helper(root->left);
		TreeNode* rt = helper(root->right);

		if (lt)
		{
			root->right = lt;
			root->left = NULL;
			while (lt && lt->right) { lt = lt->right; }
			lt->right = rt;
		}
		return root;
	}
};

void Print(TreeNode* root)
{
	while (root)
	{
		cout << root->val << " ";
		root = root->right;
	}
	cout << endl;
}

int main(void)
{
	TreeNode* root = new TreeNode(1, 
		new TreeNode(2, 
			new TreeNode(4, NULL, NULL), 
			new TreeNode(5, NULL, NULL)), 
		new TreeNode(3, NULL, 
			new TreeNode(6, NULL, 
				new TreeNode(7, NULL, NULL))));

	TreeNode* root1 = new TreeNode(1, NULL, new TreeNode(2, NULL, NULL));
	TreeNode* root2 = new TreeNode(1, new TreeNode(2, new TreeNode(4, NULL, NULL), new TreeNode(5, NULL, NULL)), new TreeNode(3, NULL, NULL));
	Solution s;
	s.flatten(root);
	s.flatten(root1);
	s.flatten(root2);
	Print(root);
	Print(root1);
	Print(root2);
	return 0;
}