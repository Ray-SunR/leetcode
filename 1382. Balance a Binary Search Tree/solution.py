# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inOrderTraversal(self, node):
        if not node:
            return
        self.inOrderTraversal(node.left)
        self.data.append(node.val)
        self.inOrderTraversal(node.right)
        
    def buildBST(self, data, l, h):
        if l > h:
            return None
        mid = int(l + (h - l) / 2)
        return TreeNode(val=data[mid], left=self.buildBST(data, l, mid - 1), right=self.buildBST(data, mid + 1, h))
    def balanceBST(self, root: TreeNode) -> TreeNode:
        self.data = []
        self.inOrderTraversal(root)
        return self.buildBST(self.data, 0, len(self.data) - 1)
        
