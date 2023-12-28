class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        j = 1
        while j < len(nums):
            while j < len(nums) and nums[j] == nums[i]:
                j += 1
            if j < len(nums):
                i += 1
                nums[i] = nums[j]
        return i + 1
