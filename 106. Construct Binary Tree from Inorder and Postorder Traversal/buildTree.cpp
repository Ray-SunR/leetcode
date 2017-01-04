#include <iostream>
#include <algorithm>
#include <vector>

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
		return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
private:
	TreeNode* helper(vector<int>& inorder, int inbegin, int inend, vector<int>& postorder, int pobegin, int poend)
	{
		//cout << "inbegin: " << inbegin << " inend: " << inend << " pobegin: " << pobegin << " poend: " << poend << endl;
		if (poend <= pobegin) { return NULL; }
		TreeNode* root = new TreeNode(postorder[poend - 1]);
		std::vector<int>::const_iterator found = std::find(inorder.begin() + inbegin, inorder.begin() + inend, postorder[poend - 1]);
		int rightsize = inend - (found - inorder.begin()) - 1;
		int leftsize = inend - inbegin - 1 - rightsize;
		//cout << "lsize: " << leftsize << " rsize: " << rightsize << endl;
		root->right = helper(inorder, found - inorder.begin() + 1, inend, postorder, poend - rightsize - 1, poend - 1);
		root->left = helper(inorder, inbegin, found - inorder.begin(), postorder, pobegin, pobegin + leftsize);
		return root;
	}
};

void Print(const TreeNode* root)
{
	if (!root) { return; }
	Print(root->left);
	cout << root->val << " ";
	Print(root->right);
}

int main(void)
{
	int in[] = { 1, 2, 3, 4, 5, 7, 8, 9};
	int po[] = { 2, 1, 4, 3, 7, 9, 8, 5};
	std::vector<int> invec(in, in  + sizeof(in) / sizeof(in[0]));
	std::vector<int> povec(po, po + sizeof(po) / sizeof(po[0]));
	Solution s;
	TreeNode* root = s.buildTree(invec, povec);
	Print(root);
	return 0;
}