# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, node, vals):
        if not node:
            return
        self.traverse(node.left, vals)
        vals.append(node.val)
        self.traverse(node.right, vals)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        vals = []
        self.traverse(root, vals)
        return vals[k - 1]
