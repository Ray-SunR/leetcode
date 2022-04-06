# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def se_helper(self, root):
        if not root:
            self.ret = self.ret + '#,'
        else:
            self.ret = self.ret + str(root.val) + ","
            self.se_helper(root.left)
            self.se_helper(root.right)

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        self.ret = ""
        self.se_helper(root)
        return self.ret
        

    def de_helper(self):
        # print(self.data)
        v = self.data[0]
        self.data = self.data[1:]
        if v == '#':
            return None
        n = TreeNode(int(v))
        n.left = self.de_helper()
        n.right = self.de_helper()
        return n
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data.split(',')
        self.data = data
        return self.de_helper()
        
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
