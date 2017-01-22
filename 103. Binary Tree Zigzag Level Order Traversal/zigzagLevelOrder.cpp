#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
	void levelOrderTraversal(TreeNode* root, int level, vector<int>& ret)
	{
		if (!root) { return; }
		if (level == 1) { ret.push_back(root->val); return; }
		levelOrderTraversal(root->left, level - 1, ret);
		levelOrderTraversal(root->right, level - 1, ret);
	}

	int height(TreeNode* root)
	{
		if (!root) { return 0; }
		return max(1 + height(root->left), 1 + height(root->right));
	}

	int max(int a, int b) { return a > b ? a : b; }

	vector<vector<int> > zigzagLevelOrder(TreeNode* root) 
	{
		vector<vector<int> > ret;
		int ht = height(root);
		for (int i = 1; i <= ht; i++)
		{
			vector<int> level;
			levelOrderTraversal(root, i, level);
			if (i % 2 == 0)
			{
				std::reverse(level.begin(), level.end());
			}
			ret.push_back(level);
		}
		return ret;
	}

	vector<vector<int> > zigzagLevelOrder1(TreeNode* root)
	{
		vector<vector<int> > ret;
		if (!root)
		{
			return ret;
		}

		deque<TreeNode*> q;
		q.push_back(root);
		int level = 0;
		while (!q.empty())
		{
			int size = q.size();
			vector<int> cur;
			while (size)
			{
				// even level. Right to left
				if (level % 2 == 0) 
				{
					TreeNode* node = q.back(); q.pop_back();
					cur.push_back(node->val);
					if (node->left)
					{
						q.push_front(node->left);
					}

					if (node->right)
					{
						q.push_front(node->right);
					}
				}
				else
				{
					TreeNode* node = q.front(); q.pop_front();
					cur.push_back(node->val);
					if (node->right)
					{
						q.push_back(node->right);
					}

					if (node->left)
					{
						q.push_back(node->left);
					}
				}
				size--;
			}
			ret.push_back(cur);
			level++;
		}
		return ret;
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
	vector<vector<int> > ret = s.zigzagLevelOrder1(root);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j =0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}