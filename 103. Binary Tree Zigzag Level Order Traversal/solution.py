# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node, lvl):
        if not node:
            return
        if lvl not in self.levels:
            self.levels[lvl] = []
        
        if lvl % 2 == 0:
            self.levels[lvl].append(node.val)
        else:
            self.levels[lvl].insert(0, node.val)
        
        self.dfs(node.left, lvl + 1)
        self.dfs(node.right, lvl + 1)
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.levels = {}
        ret = []
        i = 0
        self.dfs(root, 0)
        while i in self.levels:
            ret.append(self.levels[i])
            i += 1
        return ret