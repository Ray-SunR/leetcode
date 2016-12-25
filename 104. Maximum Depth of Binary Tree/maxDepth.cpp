#include <iostream>
#include <vector>
#include <queue>
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
	int maxDepth(TreeNode* root) {
		if (!root) { return 0; }
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
private:
	int max(int a, int b) { return a > b ? a : b; }
};

int main(void)
{
	return 0;
}