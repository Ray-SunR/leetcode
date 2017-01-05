#include <iostream>
#include <vector>
#include <queue>

/*Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.*/

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* next = NULL) : val(x), next(next) {}
};

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
	TreeNode* sortedListToBST(ListNode* head) {
		return helper(head, NULL);
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
	TreeNode* helper(ListNode* head, ListNode* tail)
	{
		if (head == tail) { return NULL; }

		ListNode* one = head;
		ListNode* two = head;
		while (two != tail)
		{
			two = two->next;
			if (!two || two == tail) { break; }
			else { two = two->next; }
			one = one->next;
		}

		TreeNode* root = new TreeNode(one->val);
		root->left = helper(head, one);
		root->right = helper(one->next, tail);
		return root;
	}
};

int main(void)
{
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, NULL))))));
	Solution s;
	TreeNode* root = s.sortedListToBST(head);
	vector<int> ret = s.levelOrderTraversal(root);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}