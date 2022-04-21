class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        d = set(nums)
        r = 0
        for n in d:
            l = 1
            if n - 1 not in d:
                x = n + 1
                while x in d:
                    x += 1
                    l += 1
                r = max(l, r)
        return r

                
