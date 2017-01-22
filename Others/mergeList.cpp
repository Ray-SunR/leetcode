#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* a, ListNode* b)
	{
		if (!a) { return b; }
		if (!b) { return a; }
		if (a->val > b->val)
		{
			ListNode* temp = a;
			a = b;
			b = temp;
		}

		ListNode* ret = a;
		ListNode* cur = ret;
		a = a->next;

		while (a && b)
		{
			if (a->val < b->val)
			{
				cur->next = a;
				cur = a;
				a = a->next;
			}
			else
			{
				cur->next = b;
				cur = b;
				b = b->next;
			}
		}

		if (a) { cur->next = a; }
		if (b) { cur->next = b; }
		return ret;
	}
};

void Print(ListNode* root)
{
	while (root)
	{
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
}

int main(void)
{
	ListNode* l1 = new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(7, NULL))));
	ListNode* l2 = new ListNode(2, new ListNode(4, new ListNode(6, NULL)));
	Solution s;
	Print(s.mergeTwoLists(l1, l2));
}