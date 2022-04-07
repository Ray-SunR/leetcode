class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # prod[i] = left[i] * right[i]
        left = [1] * len(nums)
        right = [1] * len(nums)
        i = 1
        j = len(nums) - 2
        while i < len(nums):
            left[i] = left[i - 1] * nums[i - 1]
            i += 1
        while j >= 0:
            right[j] = right[j + 1] * nums[j + 1]
            j -= 1
        
        # print(left)
        # print(right)
        ret = []
        for i in range(len(nums)):
            ret.append(left[i] * right[i])
        return ret
