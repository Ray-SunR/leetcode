class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        ret = []
        ma = float("-inf")
        prev = 0
        for i in range(len(nums)):
            ma = max(nums[i], ma)
            conver = nums[i] + ma
            ret.append(conver + prev)
            prev = ret[-1]
        return ret
