/*
Given a linked list, swap every two adjacent nodes and return 
its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify 
the values in the list, only nodes itself can be changed.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) { return head; }
		ListNode* node = head->next;
		head->next = node->next;
		node->next = head;
		head->next = swapPairs(head->next);
		return node;
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
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, NULL)))));
	ListNode* head1 = new ListNode(1, new ListNode(2, NULL));
	Solution s;
	s.Print(s.swapPairs(head));
	s.Print(s.swapPairs(head1));
	return 0;
}