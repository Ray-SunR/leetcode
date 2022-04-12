# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, node, paths):
        if not node:
            return
        if not node.left and not node.right:
            self.ret.append("->".join((paths + "#" + str(node.val)).split("#"))[2:])
            return
        self.helper(node.left, paths + "#" + str(node.val))
        self.helper(node.right, paths + "#" + str(node.val))
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.ret = []
        self.helper(root, "")
        return self.ret
        
