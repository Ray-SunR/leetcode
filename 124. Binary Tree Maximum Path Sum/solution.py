# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, node):
        if not node:
            return -math.inf
        left = self.helper(node.left)
        right = self.helper(node.right)
        self.m = max(self.m, max(left, max(right, max(left + node.val, max(right + node.val, max(left + right + node.val, node.val))))))
        # either left or right or left + node.val or right + node.val or the node itsef.
        return max(left + node.val, max(right + node.val, node.val))
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.m = -math.inf
        self.helper(root)
        return self.m
