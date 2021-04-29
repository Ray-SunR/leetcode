/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) { return null; }
        int length = length(head);
        k = k % length;
        if (k == 0) { return head; }

        ListNode pt1 = head;
        ListNode pt2 = move(pt1, k);
        while (pt2.next != null) {
            pt2 = pt2.next;
            pt1 = pt1.next;
        }
        ListNode newHead = pt1.next;
        pt1.next = null;
        pt2.next = head;
        return newHead;
    }
    
    private int length(ListNode node) {
        int length = 0;
        while (node != null) {
            length++;
            node = node.next;
        }
        return length;
    }
    
    private ListNode move(ListNode node, int k) {
        while (node != null && k != 0) {
            node = node.next;
            k--;
        }
        return node;
    }
}
