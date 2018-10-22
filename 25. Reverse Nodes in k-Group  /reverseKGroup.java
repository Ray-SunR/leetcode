class Solution {
    private ListNode reverseList(ListNode head, ListNode end) {
        ListNode endNext = end.next;
        ListNode pre = end.next;
        while (head != endNext) {
            ListNode next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    
    public ListNode reverseKGroup(ListNode head, int k) {
        if (k <= 1) { return head; }
        ListNode l1 = head;
        ListNode l2 = getL2(l1, k);
        ListNode newHead = null;
        ListNode pre = null;
        while (l2 != null) {
            ListNode nextL1 = l2.next;
            ListNode reversedHead = reverseList(l1, l2);
           
            if (pre != null) {
                pre.next = reversedHead;
            }
            
            if (newHead == null) {
                newHead = reversedHead;
            }
            pre = l1;
            l1 = nextL1;
            l2 = getL2(l1, k);
        }
        return newHead == null ? head : newHead;
    }
    
    private ListNode getL2(ListNode l1, int k) {
        ListNode l2 = l1;
        while (--k != 0 && l2 != null) { l2 = l2.next; }
        return l2;
    }
}