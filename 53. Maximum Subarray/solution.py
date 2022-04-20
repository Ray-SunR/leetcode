class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        i = 1
        while i < len(nums):
            if nums[i - 1] > 0:
                nums[i] = nums[i - 1] + nums[i]
            i += 1
        return max(nums)
