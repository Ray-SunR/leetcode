/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    private ListNode addTwoNumbersHelper(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null) {
            if (carry != 0) {
                return new ListNode(carry);
            } else {
                return null;
            }
        } 
        
        int l2Val = l2 == null ? 0 : l2.val;
        int l1Val = l1 == null ? 0 : l1.val;
        int sum = l1Val + l2Val + carry;
        
        int newCarry = sum / 10;
        int remains = sum % 10;
        final ListNode node = new ListNode(remains);
        node.next = addTwoNumbersHelper(l1 == null ? null : l1.next, l2 == null ? null : l2.next, newCarry);
        return node;
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return addTwoNumbersHelper(l1, l2, 0);
    }
}