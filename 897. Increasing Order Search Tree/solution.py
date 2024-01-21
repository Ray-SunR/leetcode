# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, node, nums):
        if not node:
            return
        self.traverse(node.left, nums)
        nums.append(node)
        self.traverse(node.right, nums)

    def construct(self, nums):
        i = 0
        while i < len(nums) - 1:
            nums[i].left = None
            nums[i].right = nums[i + 1]
            i += 1
        nums[i].left = None
        nums[i].right = None
        return nums[0]

    def increasingBST(self, root: TreeNode) -> TreeNode:
        nums = []
        self.traverse(root, nums)
        return self.construct(nums)
