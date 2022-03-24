# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self, node, depth):
        if not node:
            return depth
        return max(self.depth(node.left, depth + 1), self.depth(node.right, depth + 1))

    def helper(self, node, level, l):
        if not node:
            return
        if l[level]:
            l[level].append(node.val)
        else:
            l[level] = [node.val]
        self.helper(node.left, level + 1, l)
        self.helper(node.right, level + 1, l)
        
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # List of stacks. Each level is an entry in the list, push value to the stack at this level.
        d = self.depth(root, 0)
        l = [None] * d
        self.helper(root, 0, l)
        print(l)
        ret = []
        for i in range(d):
            ret.append(l[i][-1])
        return ret
        
        
