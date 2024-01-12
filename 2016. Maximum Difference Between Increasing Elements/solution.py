class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ret = -1
        i = 1
        start_i = 0
        while i < len(nums):
            # print(i)
            if nums[i] > nums[i - 1]:
                # print('here')
                ret = max(ret, nums[i] - nums[start_i])
            else:
                if nums[i] < nums[start_i]:
                    start_i = i
            i += 1
        return ret
