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
	int maxPathSum(TreeNode* root) {
		int max = INT_MIN;
		maxPathSumHelper(root, max);
		return max;
	}
private: 
	int maxPathSumHelper(TreeNode* root, int& max)
	{
		if (!root) { return 0; }
		int lm = maxPathSumHelper(root->left, max);
		int rm = maxPathSumHelper(root->right, max);
		if (lm < 0) { lm = 0; }
		if (rm < 0) { rm = 0; }
		if (lm + rm + root->val > max) { max = lm + rm + root->val; }
		return root->val += maxf(lm, rm);
	}

	int maxf(int a, int b) { return a > b ? a : b; }
};

int main(void)
{
	TreeNode* root = new TreeNode(1, new TreeNode(3, NULL, NULL), new TreeNode(2, NULL, NULL));
	TreeNode* root1 = new TreeNode(-2, new TreeNode(-1, NULL, NULL), NULL);
	Solution s;
	cout << s.maxPathSum(root1) << endl;
	return 0;
}