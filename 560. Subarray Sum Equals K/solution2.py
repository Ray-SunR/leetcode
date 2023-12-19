class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        culSum, count, d = 0, 0, {0: 1}
        for num in nums:
            culSum = culSum + num
            count = count + d.get(culSum - k, 0)
            d[culSum] = d.get(culSum, 0) + 1
        return count
