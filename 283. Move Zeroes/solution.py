class Solution:
    def helper(self, nums):
        d = []
        for idx in range(len(nums)):
            if nums[idx] != 0:
                d.append(nums[idx])
        idx = 0
        while idx < len(nums):
            if idx < len(d):
                nums[idx] = d[idx]
            else:
                nums[idx] = 0
            idx += 1
            
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # i = len(nums) - 1
        # while i >= 0:
        #     if nums[i] == 0:
        #         k = i
        #         j = i + 1
        #         while j < len(nums) and nums[j] != 0:
        #             tmp = nums[k]
        #             nums[k] = nums[j]
        #             nums[j] = tmp
        #             k = j
        #             j += 1
        #     i -= 1
        self.helper(nums)
