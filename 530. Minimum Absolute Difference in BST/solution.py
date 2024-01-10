# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, node, ret):
        if not node:
            return
        self.traverse(node.left, ret)
        ret.append(node.val)
        self.traverse(node.right, ret)
        
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        ret = []
        self.traverse(root, ret)
        i = 1
        diff = float('inf')
        for i in range(len(ret)):
            diff = min(diff, abs(ret[i] - ret[i - 1]))
        return diff
        
