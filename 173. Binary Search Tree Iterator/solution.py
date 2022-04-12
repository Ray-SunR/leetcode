# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def inOrder(self, node):
        if not node:
            return
        self.inOrder(node.left)
        self.data.append(node.val)
        self.inOrder(node.right)
    def __init__(self, root: Optional[TreeNode]):
        self.data = []
        self.inOrder(root)
        self.idx = 0 

    def next(self) -> int:
        v = self.data[self.idx]
        self.idx += 1
        return v

    def hasNext(self) -> bool:
        return self.idx < len(self.data)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
