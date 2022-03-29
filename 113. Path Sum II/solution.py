# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, node, s, ret, k):
        if not node:
            return
        ret.append(node.val)
        if not node.left and not node.right and node.val + s == k:
            self.rets.append(ret.copy())
        else:
            self.helper(node.left, s + node.val, ret, k)
            self.helper(node.right, s + node.val, ret, k)
        ret.pop()
            
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.rets = []
        self.helper(root, 0, [], targetSum)
        return self.rets
