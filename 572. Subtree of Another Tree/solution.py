# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inOrder(self, node, ret):
        if not node:
            return
        ret.append('[')
        self.inOrder(node.left, ret)
        ret.append(str(node.val))
        self.inOrder(node.right, ret)
        ret.append(']')
    def preOrder(self, node, ret):
        if not node:
            return
        ret.append(str(node.val))
        self.preOrder(node.left, ret)
        self.preOrder(node.right, ret)
    
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        root_in_order = []
        root_pre_order = []
        self.inOrder(root, root_in_order)
        self.preOrder(root, root_pre_order)
        
        root_in_order = ','.join(root_in_order)
        root_pre_order = ','.join(root_pre_order)
        
        sub_in_order = []
        sub_pre_order = []
        self.inOrder(subRoot, sub_in_order)
        self.preOrder(subRoot, sub_pre_order)
        sub_in_order = ','.join(sub_in_order)
        sub_pre_order = ','.join(sub_pre_order)
        # print(root_in_order)
        # print(root_pre_order)
        # print(sub_in_order)
        # print(sub_pre_order)
        # print('----')
        
        return sub_in_order in root_in_order and sub_pre_order in root_pre_order
        
        
        
        
