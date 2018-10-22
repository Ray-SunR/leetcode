/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    private ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null) { return l2; }
        if (l2 == null) { return l1; }
        ListNode head, start;
        if (l1.val <= l2.val) {
            head = l1;
            l1 = l1.next;
        } else {
            head = l2;
            l2 = l2.next;
        }
        start = head;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                start.next = l1;
                start = l1;
                l1 = l1.next;
            } else {
                start.next = l2;
                start = l2;
                l2 = l2.next;
            }
        }
        
        if (l1 == null) { start.next = l2; }
        if (l2 == null) { start.next = l1; }
        return head;
    }
    
    private ListNode merge(ListNode[] lists, int low, int high) {
        if (low >= high) { return lists[high]; }
        int mid = low + (high - low) / 2;
        ListNode l1 = merge(lists, low, mid);
        ListNode l2 = merge(lists, mid + 1, high);
        return merge(l1, l2);
    } 
    
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) { return null; }
        return merge(lists, 0, lists.length - 1);
    }
}