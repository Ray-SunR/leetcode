# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, node, low, high):
        if not node:
            return
        if node.val <= high and node.val >= low:
            self.ret += node.val
        if node.val > high:
            self.helper(node.left, low, high)
        elif node.val < low:
            self.helper(node.right, low, high)
        else:
            self.helper(node.left, low, high)
            self.helper(node.right, low, high)
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.ret = 0
        self.helper(root, low, high)
        return self.ret
            
