class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null) { return head; }
        ListNode l1 = head;
        ListNode l2 = head.next;
        ListNode newHead = l2 != null ? l2 : l1;
        ListNode pre = new ListNode(0); pre.next = l1;
        while (l2 != null) {
            pre = swap(l1, l2, pre);
            if (pre == null) { return newHead; }
            l1 = pre.next;
            if (l1 == null) { return newHead; }
            l2 = l1.next;
        }
        return newHead;
    }
    
    private ListNode swap(ListNode l1, ListNode l2, ListNode pre) {
        l1.next = l2.next;
        l2.next = l1;
        pre.next = l2;
        return l1;
    }
}