class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        b = nums[::-1]
        i = 1
        while i < len(nums):
            if nums[i - 1] != 0:
                nums[i] *= nums[i - 1]
            if b[i - 1] != 0:
                b[i] *= b[i - 1]
            i += 1
        # print(nums)
        # print(b)
        return max(max(nums), max(b))
