# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class CBTInserter:

    def find_insert_pos(self, node, lvl):
        if node.left and not node.right:
            return node, lvl
        if not node.left:
            return node, lvl
        ln, left_lvl = self.find_insert_pos(node.left, lvl + 1)
        rn, right_lvl = self.find_insert_pos(node.right, lvl + 1)
        # print('left,lvl: ' + str(ln.val) + ',' + str(left_lvl) + ' right: ' + str(rn.val) + ',' + str(right_lvl))
        if left_lvl < right_lvl:
            return ln, left_lvl
        elif left_lvl > right_lvl:
            return rn, right_lvl
        else:
            return ln, left_lvl
        
    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.next_insert_pos, lvl = self.find_insert_pos(self.root, 0)

    def insert(self, val: int) -> int:
        n = self.next_insert_pos
        # print("insert parent: " + str(n.val))
        tn = TreeNode(val)
        if not n.left:
            n.left = tn
        else:
            n.right = tn
        self.next_insert_pos, lvl = self.find_insert_pos(self.root, 0)
        return n.val
        
    
    def get_root(self) -> Optional[TreeNode]:
        return self.root


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()
