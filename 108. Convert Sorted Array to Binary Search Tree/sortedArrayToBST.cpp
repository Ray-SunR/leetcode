#include <iostream>
#include <vector>
#include <queue>
/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size());
	}


	std::vector<int> levelOrderTraversal(TreeNode* root) const
	{
		std::vector<int> ret;
		if (!root) { return ret; }
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* front = q.front(); q.pop();
			if (!front) { continue; }
			ret.push_back(front->val);
			q.push(front->left);
			q.push(front->right);
		}
		return ret;
	}
private:
	TreeNode* helper(vector<int>& nums, int begin, int end)
	{
		if (end <= begin) { return NULL; }
		int mid = begin + (end - 1 - begin) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		cout << "root: " << nums[mid] << endl;
		root->left = helper(nums, begin, mid);
		root->right = helper(nums, mid + 1, end);
		return root;
	}
};

int main(void)
{
	int data[] = {1, 2, 3, 4, 5, 6};
	vector<int> vec(data, data + sizeof(data) / sizeof(data[0]));
	Solution s;
	TreeNode* root = s.sortedArrayToBST(vec);
	vector<int> ret = s.levelOrderTraversal(root);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}