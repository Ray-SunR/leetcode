class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        j = 1
        increasing = None
        while j < len(nums):
            if nums[j] == nums[j - 1]:
                j += 1
                continue
            if increasing is None:
                increasing = True if nums[j] > nums[j - 1] else False
            elif increasing and nums[j] < nums[j - 1]:
                return False
            elif not increasing and nums[j] > nums[j - 1]:
                return False
            j += 1
        return True
