/*
Given a linked list, remove the nth node from the end of list 
and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked 
list becomes 1->2->3->5.
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x, ListNode* next = NULL) 
 	: val(x), next(next) {}
 };

 class Solution {
 public:
 	ListNode* removeNthFromEnd(ListNode* head, int n) {
 		if (!head) { return head; }
 		ListNode* p1 = head;
 		ListNode* p2 = p1;
 		while (p2 && n) { p2 = p2->next; n--; }
 		if (!p2) { ListNode* tod = head; head = head->next; delete tod; return head; }
 		ListNode* pre = p1;
 		while (p2)
 		{
 			pre = p1;
 			p1 = p1->next;
 			p2 = p2->next;
 		}

 		if (p1)
 		{
	 		pre->next = p1->next;
 			delete p1;
 		}
 		return head;
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
 	ListNode* test1 = 
 	new ListNode(1,
 		new ListNode(2, 
 			new ListNode(3, 
 				new ListNode(4, 
 					new ListNode(5, NULL)))));
 	ListNode* test11 = 
 	new ListNode(1,
 		new ListNode(2, 
 			new ListNode(3, 
 				new ListNode(4, 
 					new ListNode(5, NULL)))));
 	ListNode* test111 = 
 	new ListNode(1,
 		new ListNode(2, 
 			new ListNode(3, 
 				new ListNode(4, 
 					new ListNode(5, NULL)))));
 	ListNode* test2 = new ListNode(1, NULL);
 	ListNode* test3 = NULL;
 	ListNode* test4 = new ListNode(1, new ListNode(2, NULL));
 	Solution s;

 	Print(test1);
 	ListNode* head1 = s.removeNthFromEnd(test1, 0);
 	Print(head1);
 	cout << "----" << endl;
 	Print(test11);
 	ListNode* head2 = s.removeNthFromEnd(test11, 100);
 	Print(head2);
 	cout << "----" << endl;
 	Print(test111);
 	ListNode* head3 = s.removeNthFromEnd(test111, 2);
 	Print(head3);
 	cout << "----" << endl;
 	Print(test2);
 	ListNode* head4 = s.removeNthFromEnd(test2, 1);
 	Print(head4);
 	cout << "----" << endl;
 	delete head1;
 	delete head2;
 	delete head3;
 	delete head4;
 	return 0;
 }