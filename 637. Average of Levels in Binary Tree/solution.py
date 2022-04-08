# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def level(self, node):
        if not node:
            return 0
        return 1 + max(self.level(node.left), self.level(node.right))
    def visit(self, node, lvl):
        if not node:
            return
        if not self.data[lvl]:
            self.data[lvl] = []
        self.data[lvl].append(node.val)
        self.visit(node.left, lvl + 1)
        self.visit(node.right, lvl + 1)
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        lvl = self.level(root)
        self.data = [None] * lvl
        self.visit(root, 0)
        ret = []
        for lvl_data in self.data:
            su = 0
            for d in lvl_data:
                su += d
            ret.append(su / len(lvl_data))
        return ret
