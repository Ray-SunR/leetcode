//
// Created by SunRenchen on 2015-04-28.
//

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 */

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* Helper(ListNode* l1, ListNode* l2, int carryover)
    {
        if (!l1 && !l2)
        {
            return carryover == 0 ? NULL : new ListNode(carryover);
        }

        int newCarryover = 0;
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carryover;

        int intPart = sum / 10;
        int remainder = sum % 10;
        cout << "Sum: " << sum << endl;
        cout << "intPart: " << intPart << endl;
        cout << "remainder: " << remainder << endl;

        ListNode* next = Helper(l1 ? l1->next : NULL, l2 ? l2->next : NULL, intPart);
        ListNode* that = new ListNode(remainder);
        that->next = next;
        return that;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return Helper(l1, l2, 0);
    }
};

void PrintList(ListNode* head)
{
    if (!head) {return;}
    cout << head->val << " ";
    PrintList(head->next);
}

int main(void)
{
    Solution s;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(1);

    ListNode* l3 = s.addTwoNumbers(l1, l2);
    PrintList(l3);
    return 0;
}
