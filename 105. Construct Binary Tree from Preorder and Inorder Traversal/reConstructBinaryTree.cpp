/*
Given preorder and inorder traversal of a tree, construct the binary tree.
*/
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* left = NULL, TreeNode* right = NULL) : val(x), left(left), right(right) {}
};

class Solution {
public:
	struct TreeNode* reConstructBinaryTree(const vector<int>& pre, const vector<int>& in) {
		TreeNode* ret = NULL;
		if (pre.empty() || in.empty()) { return ret; }
		ret = new TreeNode(pre[0]);
		vector<int>::const_iterator it = std::find(in.begin(), in.end(), pre[0]);
		int pos = it - in.begin();
		ret->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + 1 + pos), vector<int>(in.begin(), in.begin() + pos));
		ret->right = reConstructBinaryTree(vector<int>(pre.begin() + 1 + pos, pre.end()), vector<int>(in.begin() + pos + 1, in.end()));
		return ret;	
	}

	TreeNode* helper(const vector<int>& pre, int preb, int pree, const vector<int>& in, int inb, int ine)
	{
		TreeNode* ret = NULL;
		if (pree == preb || inb == ine) { return ret; }
		ret = new TreeNode(pre[preb]);
		vector<int>::const_iterator it = std::find(in.begin() + inb, in.begin() + ine, pre[preb]);
		int size = it - in.begin() - inb;
		ret->left = helper(pre, preb + 1, preb + 1 + size, in, inb, inb + size);
		ret->right = helper(pre, preb + 1 + size, pree, in, inb + size + 1, ine);
		return ret;
	}

	TreeNode* reConstructBinaryTree1(const vector<int>& pre, const vector<int>& in){
		return helper(pre, 0, pre.size(), in, 0, in.size());
	}
};

void PreOrder(const TreeNode* root)
{
	if (!root) { return; }
	cout << root->val << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(const TreeNode* root)
{
	if (!root) { return; }
	InOrder(root->left);
	cout << root->val << " ";
	InOrder(root->right);
}

int main(void)
{
	//TreeNode* root = new TreeNode(1, new TreeNode(2, NULL, new TreeNode(3, NULL, NULL)), new TreeNode(4, new TreeNode(5, NULL, NULL), NULL));
	vector<int> in, pre;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(3);
	pre.push_back(4);

	in.push_back(1);
	in.push_back(2);
	in.push_back(3);
	in.push_back(4);

	Solution s;
	TreeNode* root = s.reConstructBinaryTree1(pre, in);
	InOrder(root);
	cout << endl;
	PreOrder(root);
	cout << endl;
	return 0;
}