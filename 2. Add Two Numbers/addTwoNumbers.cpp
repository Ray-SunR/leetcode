/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain
 a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* next = NULL) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbersRecursive(ListNode* l1, ListNode* l2, int co)
	{
		if (!l1 && !l2 && co == 0) { return NULL; }
		int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + co;
		int remainder = val % 10;
		co = val / 10;
		ListNode* ret = new ListNode(remainder);
		ret->next = addTwoNumbersRecursive(l1 ? l1->next : NULL, l2 ? l2->next : NULL, co);
		return ret;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int co = 0;
		ListNode* ret = NULL;
		ListNode* node = NULL;
		while (l1 && l2)
		{
			int val = l1->val + l2->val + co;
			int remainder = val % 10;
			co = val / 10;

			if (node)
			{
				node->next = new ListNode(remainder);
				node = node->next;
			}
			else
			{
				node = new ListNode(remainder);
				ret = node;
			}

			l1 = l1->next;
			l2 = l2->next;
		}

		ListNode* l = l1 ? l1 : l2;
		while (l)
		{
			int val = l->val + co;
			int remainder = val % 10;
			co = val / 10;
			if (node)
			{
				node->next = new ListNode(remainder);
				node = node->next;
			}
			else
			{
				node = new ListNode(remainder);
				ret = node;
			}
			l = l->next;
		}

		if (co)
		{
			if (node)
			{
				node->next = new ListNode(co);
				node = node->next;
			}
			else
			{
				node = new ListNode(co);
				ret = node;
			}
		}

		return ret;
	}

	void Print(const ListNode* head)
	{
		while (head)
		{
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
};

int main(void)
{
	ListNode* l3 = new ListNode(0, NULL);
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, NULL)));
	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(6, new ListNode(9, new ListNode(9, NULL)))));
	Solution s;
	ListNode* ret = s.addTwoNumbersRecursive(l1, l2, 0);
	s.Print(ret);
	delete l1;
	delete l2;
	delete ret;
	return 0;
}