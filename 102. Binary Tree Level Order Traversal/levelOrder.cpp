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
	vector<vector<int> > levelOrder(TreeNode* root)
	{
		int ht = height(root);
		vector<vector<int> > ret;
		for (int i = 1; i <= ht; i++)
		{
			vector<int> level;
			PrintLevel(root, i, level);
			ret.push_back(level);
		}
		return ret;
	}

private:
	int height(TreeNode* root)
	{
		if (!root) { return 0; }
		return 1 + max(height(root->left), height(root->right));
	}

	int max(int a, int b) { return a > b ? a : b; }

	void PrintLevel(TreeNode* root, int level, vector<int>& ret)
	{
		if (!root) { return; }
		if (level == 1) { ret.push_back(root->val); return; }
		PrintLevel(root->left, level - 1, ret);
		PrintLevel(root->right, level - 1, ret);
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
	vector<vector<int> > ret = s.levelOrder(root);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	delete root;
	return 0;
}