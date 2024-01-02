# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lca(self, node, node1, node2):
        if not node:
            return None
        # print(node.val)
        if node == node1:
            return node
        if node == node2:
            return node
        left = self.lca(node.left, node1, node2)
        right = self.lca(node.right, node1, node2)
        # print('left: {}, right: {}'.format(left, right))
        if left and right:
            return node
        elif left:
            return left
        else:
            return right
        
    def find_depth(self, node):
        if not node:
            return 0
        return max(1 + self.find_depth(node.left), 1 + self.find_depth(node.right))

    def find_leaves(self, node, x, depth, ret):
        if not node:
            return

        if depth == 0:
            ret.append(node)
            return
        
        self.find_leaves(node.left, x - 1, depth - 1, ret)
        self.find_leaves(node.right, x + 1, depth - 1, ret)
    
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        depth = self.find_depth(root)
        leaves = []
        self.find_leaves(root, 0, depth - 1, leaves)
        # leaves = sorted(leaves, key=lambda x: x[0])
        # print('depth: {}, leaves: {}'.format(depth, leaves))

        i = 0
        lca = None
        while i < len(leaves):
            lca = self.lca(root, lca, leaves[i])
            i += 1
        # lca = self.lca(root, leaves[0][1], leaves[-1][1])
        # print(lca)
        return lca

        
