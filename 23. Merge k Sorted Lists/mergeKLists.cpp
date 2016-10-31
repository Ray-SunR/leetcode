/*Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.*/

#include <iostream>
#include <vector>
using namespace std;

// 1: 3->5->7->9
// 2: 1->2->3->4
// 3: 7->8->10->12
// Thoughts: use divide-conquer idea to divide n lists -> m pairs of lists
// merge each pair individually and then merge. 

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// 1 2 3 4 5
// 1 2 - > (1, 2)
// 3 4 5 -> 
// 3 -> 3         ->
// 4 5 -> (4, 5)  ->
class Solution {
public:
	ListNode* mergeKLists(const vector<ListNode*>& lists) {
		if (lists.empty()) { return NULL; }
		if (lists.size() == 1)
		{
			return lists[0];
		}
		if (lists.size() == 2) 
		{
			return mergeTwoLists(lists[0], lists[1]);
		}

		ListNode* one = mergeKLists(vector<ListNode*>(lists.begin(), lists.begin() + lists.size() / 2));
		ListNode* two = mergeKLists(vector<ListNode*>(lists.begin() + lists.size() / 2, lists.end()));
		return mergeTwoLists(one, two);
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		if (list1 == list2) { return list1; }
		if (list1 && !list2) { return list1; }
		if (!list1 && list2) { return list2; }

		ListNode* ret = list1->val < list2->val ? list1 : list2;
		ListNode* helper = ret;
		if (ret == list1) { list1 = list1->next; }
		if (ret == list2) { list2 = list2->next; }
		while (list1 && list2)
		{
			if (list1->val < list2->val) { helper->next = list1; list1 = list1->next; }
			else { helper->next = list2; list2 = list2->next; }
			helper = helper->next;
		}

		if (list1) { helper->next = list1; }
		if (list2) { helper->next = list2; }
		return ret;
	}

	void Print(ListNode* list)
	{
		while (list)
		{
			cout << list->val << " ";
			list = list->next;
		}
		cout << endl;
	}
};

int main(void)
{
	ListNode* list1, *list2, *list3, *list4, *list5;
	list1 = new ListNode(3, new ListNode(5, new ListNode(7, new ListNode(9, new ListNode(12, NULL)))));
	list2 = new ListNode(1, new ListNode(4, new ListNode(10, NULL)));
	list3 = new ListNode(2, new ListNode(8, new ListNode(11, new ListNode(19, NULL))));
	list4 = new ListNode(0, NULL);
	list5 = new ListNode(18, new ListNode(21, NULL));
	vector<ListNode*> lists;
	lists.push_back(list1);
	lists.push_back(list2);
	lists.push_back(list3);
	lists.push_back(list4);
	lists.push_back(list5);

	vector<ListNode*> lists1;
	lists1.push_back(list1);
	lists1.push_back(list3);
	lists1.push_back(list5);

	Solution s;
	s.Print(s.mergeKLists(lists1));

	return 0;
}