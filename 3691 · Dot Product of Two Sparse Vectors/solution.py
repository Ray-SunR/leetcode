from typing import (
    List,
)

class SparseVector:
    # Your SparseVector object will be instantiated and called as such:
    # v1 = SparseVector(nums1)
    # v2 = SparseVector(nums2)
    # ans = v1.dot_product(v2)
    def __init__(self, nums: List[int]):
        # do intialization here
        self.nums = nums

    # Return the dotProduct of two sparse vectors
    def dot_product(self, vec: "SparseVector") -> int:
        # write your code here
        ret = 0
        for i, val in enumerate(vec.nums):
            ret += self.nums[i] * val
        return ret
