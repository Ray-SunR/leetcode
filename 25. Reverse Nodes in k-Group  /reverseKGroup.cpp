/*
Given a linked list, reverse the nodes of a linked list k at a 
time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes
in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may 
be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

// Thoughts: divide-conqur, basically divide the list into serval k-groups. 
// Then our job is to reverse each group and connect them together. 
// This is similar as reverse link list problem except that the ordinary 
// reverse linked list problem has a group size of 1. The most important
// part is to figure out the 'pre' element. e.g for the first group, it 
// requests the 'pre' element which can be got from group 2, and group2
// can get from group3, etc. 
#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* first = head;
		ListNode* second = head;
		int count = k - 1;
		while (second && count > 0) { second = second->next; count--; }
		if (second)
		{
			ListNode* pre = reverseKGroup(second->next, k);
			ListNode* node = first;
			ListNode* end = second->next;
			while (node != end)
			{
				ListNode* next = node->next;
				node->next = pre;
				pre = node;
				node = next;
			}
			return pre;
		}
		else
		{
			return head;
		}
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
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, NULL))))));
	Solution s;
	s.Print(s.reverseKGroup(head, 2));
	return 0;
}