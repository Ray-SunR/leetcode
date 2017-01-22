#include <iostream>
#include <vector>
using namespace std;
/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x, TreeLinkNode* left = NULL, TreeLinkNode* right = NULL) 
	: val(x), left(left), right(right), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) 
	{
		int height = Height(root);
		for (int i = 1; i <= height; i++)
		{
			std::vector<TreeLinkNode*> ret;
			LevelOrderTraversal(root, i, ret);
			for (int i = 0, j = 1; j < ret.size(); i++, j++)
			{
				ret[i]->next = ret[j];
			}
		}
	}

	void LevelOrderTraversal(TreeLinkNode* node, int level, std::vector<TreeLinkNode*>& ret)
	{
		if (!node) { return; }
		if (level == 1) { ret.push_back(node); return; }
		LevelOrderTraversal(node->left, level - 1, ret);
		LevelOrderTraversal(node->right, level - 1, ret);
	}

	int Height(TreeLinkNode* root)
	{
		if (!root) { return 0; }
		return max(Height(root->left) + 1, Height(root->right) + 1);
	}

	int max(int a, int b) { return a > b ? a : b; }
};

void Print(TreeLinkNode* root)
{
	while (root) { cout << root->val << " "; root = root->next; }
	cout << endl;
}

int main(void)
{
	TreeLinkNode* root = new TreeLinkNode(1, 
		new TreeLinkNode(2, new TreeLinkNode(4, NULL, NULL), new TreeLinkNode(5, NULL, NULL)), 
		new TreeLinkNode(3, NULL, new TreeLinkNode(7, NULL, NULL)));
	Solution s;
	int height = s.Height(root);
	for (int i = 1;  i <= height; i++)
	{
		std::vector<TreeLinkNode*> ret;
		s.LevelOrderTraversal(root, i, ret);
		for (int i = 0; i < ret.size(); i++)
		{
			cout << ret[i]->val << " ";
		}
		cout << endl;
	}

	s.connect(root);
	Print(root);
	Print(root->left);
	Print(root->left->left);
	return 0;
}