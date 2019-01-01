# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbersHelper(self, l1, l2, carry):
        if l1 is None and l2 is None and carry == 0:
            return None
        l1Val = l1.val if l1 != None else 0
        l2Val = l2.val if l2 != None else 0
        val = l1Val + l2Val + carry
        intPart = val / 10
        remainder = val % 10
        node = ListNode(remainder)
        node.next = self.addTwoNumbersHelper(l1.next if l1 != None else None, l2.next if l2 != None else None, intPart)
        return node
    
    def addTwoNumbers(self, l1, l2):
        """
            :type l1: ListNode
            :type l2: ListNode
            :rtype: ListNode
            """
        return self.addTwoNumbersHelper(l1, l2, 0)
