class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        ideal = ret = 0
        for n in sorted(nums):
            ret += max(0, ideal - n)
            ideal = max(ideal + 1, n + 1)
        return ret
