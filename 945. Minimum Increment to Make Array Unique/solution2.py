class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        # [3,2,1,2,1,7] -> [1, 1, 2, 2, 3, 7]
        nums = sorted(nums)
        i = 1
        cnt = 0
        while i < len(nums):
            if nums[i] <= nums[i - 1]:
                cnt += nums[i - 1] + 1 - nums[i]
                nums[i] = nums[i - 1] + 1
            i += 1
        # print(nums)
        return cnt