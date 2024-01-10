# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def get_leaves(self, node, ret):
        if not node:
            return None
        if not node.left and not node.right:
            ret.append(node.val)
            return
        self.get_leaves(node.left, ret)
        self.get_leaves(node.right, ret)
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        ret1 = []
        self.get_leaves(root1, ret1)
        ret2 = []
        self.get_leaves(root2, ret2)
        return ret1 == ret2
        
