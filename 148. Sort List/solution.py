# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        d = {}
        s = head
        v = set()
        while s:
            if s.val not in d:
                d[s.val] = []
            t = s.next
            d[s.val].append(s)
            v.add(s.val)
            s.next = None
            s = t
        v = sorted(v)
        
        head = None
        prev = None
        # print(d)
        for key in v:
            if not head:
                head = d[key][0]
            else:
                prev.next = d[key][0]
            i = 1
            n = d[key][0]
            while i < len(d[key]):
                n.next = d[key][i]
                n = d[key][i]
                i += 1
            prev = n
        return head
