"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copy(self, node, d):
        if not node:
            return None
        n = Node(node.val, next=self.copy(node.next, d), random=None)
        d[id(node)] = n
        return n
    def set_random(self, old_node, d):
        node = old_node
        while node:
            if node.random:
                d[id(node)].random = d[id(node.random)]
            node = node.next
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        d = {}
        new_head = self.copy(head, d)
        self.set_random(head, d)
        return new_head

