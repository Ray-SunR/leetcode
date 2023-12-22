class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        d = set()
        for num in nums:
            d.add(num)
        ret = 0
        for num in nums:
            count = 1
            val = num
            if val + 1 not in d:
                while val - 1 in d:
                    count += 1
                    val = val - 1
            ret = max(count, ret)
        return ret
