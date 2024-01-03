class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stk = []
        ret = [-1] * len(nums) * 2
        nums = nums + nums
        # from left to right
        for i, num in enumerate(nums):
            while stk and nums[stk[-1]] < num:
                ret[stk.pop()] = num
            stk.append(i)
        # print(ret)

        return ret[:len(nums) // 2]
