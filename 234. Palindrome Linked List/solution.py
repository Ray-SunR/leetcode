# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def find_mid_node(self, head):
        slow = head
        fast = head.next
        while fast:
            fast = fast.next
            if fast:
                fast = fast.next
            else:
                return slow
            slow = slow.next
        return slow
    def reverse_list(self, node):
        if not node:
            return None
        prev = None
        n = node
        while n:
            ne = n.next
            n.next = prev
            prev = n
            n = ne

        return prev

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        mid = self.find_mid_node(head)
        # print(mid.val)
        second_half = mid.next
        # print(second_half.val)
        first_half = head
        if not second_half:
            return True
        second_half = self.reverse_list(second_half)
        # print(second_half.val)

        while second_half and first_half and second_half.val == first_half.val:
            second_half = second_half.next
            first_half = first_half.next
        if second_half and first_half and second_half.val != first_half.val:
            return False
        return True

        
