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
	bool isBalanced(TreeNode* root) {
		if (!root) { return true; }
		int lt = height(root->left);
		int rt = height(root->right);
		if (abs(lt - rt) > 1) { return false; }
		return isBalanced(root->left) && isBalanced(root->right);
	}

private:
	int height(TreeNode* root)
	{
		if (!root) { return 0; }
		return 1 + max(height(root->left), height(root->right));
	}

	int max(int a, int b) { return a > b ? a : b; }

	int abs(int a) { return a > 0 ? a : -a; }
};

int main(void)
{
	return 0;
}