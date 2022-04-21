class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        x = nums[0]
        i = 1
        while i < len(nums):
            x ^= nums[i]
            i += 1
        return x
