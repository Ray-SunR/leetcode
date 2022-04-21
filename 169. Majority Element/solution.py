class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = {}
        ret = nums[0]
        for n in nums:
            if n not in d:
                d[n] = 0
            d[n] += 1
            if d[ret] < d[n]:
                ret = n
        return ret
        
