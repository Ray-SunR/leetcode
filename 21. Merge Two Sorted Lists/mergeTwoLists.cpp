/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes 
of the first two lists.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* next = NULL) : val(x), next(next) {}
};

//l1: 1 3 5 7 9 
//l2: 2 4 6 8 10 11 12

// ret = 1; node = ret; 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 && !l2) { return NULL; }
		else if (!l1 && l2) { return l2; }
		else if (l1 && !l2) { return l1; }
		ListNode* ret = NULL;
		if (l1->val < l2->val)
		{
			ret = l1;
			l1 = l1->next;
		}
		else
		{
			ret = l2;
			l2 = l2->next;
		}

		ListNode* node = ret;
		cout << "head: " << ret->val << endl;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cout << "link to l1: " << l1->val << endl;
				node->next = l1;
				node = l1;
				l1 = l1->next;
			}
			else
			{
				cout << "link to l2: " << l2->val << endl;
				node->next = l2;
				node = l2;
				l2 = l2->next;
			}
		}

		if (l1) { node->next = l1; }
		if (l2) { node->next = l2; }
		return ret;
	}
};

void Print(const ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main(void)
{
	ListNode* l1 = new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(10, NULL))));
	ListNode* l2 = new ListNode(0, new ListNode(2, new ListNode(9, NULL)));
	Solution s;
	ListNode* ret = s.mergeTwoLists(l1, l2);
	Print(ret);
	return 0;
}
