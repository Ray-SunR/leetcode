#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val): val(val), left(NULL), right(NULL){}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		inorderTraversalHelper(root, ret);
		return ret;
	}
private:
	void inorderTraversalHelper(TreeNode* root, vector<int>& ret)
	{
		if (!root) { return; }
		inorderTraversalHelper(root->left, ret);
		ret.push_back(root->val);
		inorderTraversalHelper(root->right, ret);
	}
};

int main(void)
{
	return 0;
}