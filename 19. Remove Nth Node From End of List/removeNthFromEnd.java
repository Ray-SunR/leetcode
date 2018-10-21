/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || (head.next == null && n == 1)) {
            return null;
        }
        ListNode pre = null;
        ListNode p1 = head;
        ListNode p2 = head;
        while (n > 0) {
            p2 = p2.next;
            n--;
        }
        
        while (p2 != null) {
            pre = p1;
            p1 = p1.next; p2 = p2.next;
        }
        
        if (pre != null) {
            pre.next = p1.next;
        } else {
            return p1.next;
        }
       
        return head;
    }
}