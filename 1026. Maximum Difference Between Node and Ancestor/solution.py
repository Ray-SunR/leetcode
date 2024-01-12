# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, node):
        left_min, right_min = node.val, node.val
        left_max, right_max = node.val, node.val
        if node.left:
            left_min, left_max = self.helper(node.left)

        if node.right:
            right_min, right_max = self.helper(node.right)

        self.ret = max(self.ret, abs(node.val - min(left_min, right_min)))
        self.ret = max(self.ret, abs(node.val - max(left_max, right_max)))

        return min(node.val, min(left_min, right_min)), max(
            node.val, max(left_max, right_max)
        )

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.ret = float("-inf")
        self.helper(root)
        return self.ret
        return self.ret
