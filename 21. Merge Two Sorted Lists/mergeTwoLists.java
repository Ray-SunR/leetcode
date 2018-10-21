/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) { return l2; }
        if (l2 == null) { return l1; }
        ListNode head;
        if (l1.val <= l2.val) {
            head = l1;
            l1 = l1.next;
        } else {
            head = l2;
            l2 = l2.next;
        }
        ListNode start = head;
        while (l1 != null && l2 != null) {
            while (l1 != null && l2 != null && l1.val <= l2.val) {
                start.next = l1;
                start = l1;
                l1 = l1.next;
            } 
            while (l2 != null && l1 != null && l2.val < l1.val) {
                start.next = l2;
                start = l2;
                l2 = l2.next;
            }
        }
        if (l1 == null) { 
            start.next = l2;        
        } 
        if (l2 == null) {
            start.next = l1;
        }
        return head;
    }
}