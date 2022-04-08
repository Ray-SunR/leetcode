# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, n):
        prev = None
        while n:
            nex = n.next
            n.next = prev
            prev = n
            n = nex
        return prev

    def helper(self, n1, n2, carry):
        if not n1 and not n2 and carry:
            return ListNode(carry)
        elif not n1 and not n2:
            return None
        elif n1 and n2:
            val = n1.val + n2.val + carry
            carry = int(val / 10)
            val = val % 10
            n = ListNode(val)
            n.next = self.helper(n1.next, n2.next, carry)
            return n
        elif not n1:
            val = n2.val + carry
            carry = int(val / 10)
            val = val % 10
            n = ListNode(val)
            n.next = self.helper(n1, n2.next, carry)
            return n
        else:
            val = n1.val + carry
            carry = int(val / 10)
            val = val % 10
            n = ListNode(val)
            n.next = self.helper(n1.next, n2, carry)
            return n
    def print(self, l):
        while l:
            print(l.val)
            l = l.next
            
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)
        # self.print(l1)
        # self.print(l2)
        l = self.helper(l1, l2, 0)
        return self.reverse(l)
        
