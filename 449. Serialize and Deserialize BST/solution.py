# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def se_helper(self, node):
        if not node:
            return "#"
        return str(node.val) + ","  + self.se_helper(node.left) + "," + self.se_helper(node.right)

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        s = self.se_helper(root)
        print(s)
        return s
        

    def de_helper(self):
        print(id(self.data))
        val = self.data[0]
        self.data = self.data[1:]
        if not self.data or val == '#':
            return None
        
        n = TreeNode(int(val))
        n.left = self.de_helper()
        n.right = self.de_helper()
        return n

    def de_helper2(self, data):
        # print(id(data))
        val = data[0]
        data.pop(0)
        if not data or val == '#':
            return None
        
        n = TreeNode(int(val))
        n.left = self.de_helper2(data)
        n.right = self.de_helper2(data)
        return n
            
    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        # self.data = data.split(',')
        
        # return self.de_helper()
        data = data.split(',')
        return self.de_helper2(data)
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
