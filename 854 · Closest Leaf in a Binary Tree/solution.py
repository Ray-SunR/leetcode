from lintcode import (
    TreeNode,
)

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    def traverse(self, parent, node, k):
        if not node:
            return
        self.parents[node.val] = parent

        if node.val == k:
            self.target = node
        self.traverse(node, node.left, k)
        self.traverse(node, node.right, k)

    def find(self, node, path):
        if not node:
            return None, 0
        if not node.left and not node.right:
            return node, path
        n1, p1 = self.find(node.left, path + 1)
        n2, p2 = self.find(node.right, path + 1)
        if p1 and not p2:
            return n1, p1
        elif not p1 and p2:
            return n2, p2
        elif p1 <= p2:
            return n1, p1
        else:
            return n2, p2
    """
    @param root: the root
    @param k: an integer
    @return: the value of the nearest leaf node to target k in the tree
    """
    def find_closest_leaf(self, root: TreeNode, k: int) -> int:
        # Write your code here
        self.parents = {}
        self.target = None
        self.traverse(None, root, k)
        closest_node1, path1 = self.find(self.target, 0)
        if self.parents[k]:
            closest_node2, path2 = self.find(self.parents[k], 1)
            return closest_node1.val if path1 <= path2 else closest_node2.val
        return closest_node1.val

'''
      1
   3.    4
           9
             10
'''

