# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import OrderedDict

class Solution:
    # coords: {-1: 9, 0: [3, 15], 1: [20], 2: [7]}
    #
    def parse(self, node, x, y, coords):
        if not node:
            return
        if y not in coords:
            # Use OrderedDict to maintain the insertion order
            coords[y] = OrderedDict()
        if x not in coords[y]:
            coords[y][x] = []
        coords[y][x].append(node.val)
        self.parse(node.left, x + 1, y - 1, coords)
        self.parse(node.right, x + 1, y + 1, coords)
        
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        # index is column
        # {-2: { 2: [4]}, 1: { 1: [2]}, 0: {0: [1], 2: [6, 5]}, 1: {1: [3]}, 2: {2: 7}}
        coords = {}
        ret = []
        self.parse(root, 0, 0, coords)
        # print(coords)
        for column in sorted(coords):
            column_ret = []
            for key in sorted(coords[column]):
                for val in sorted(coords[column][key]):
                    column_ret.append(val)
            ret.append(column_ret)
        return ret
