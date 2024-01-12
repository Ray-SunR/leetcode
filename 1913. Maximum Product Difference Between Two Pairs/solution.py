class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        heapq.heapify(nums)
        low1 = heapq.heappop(nums)
        low2 = heapq.heappop(nums)

        nums = [-x for x in nums]
        heapq.heapify(nums)
        high1 = heapq.heappop(nums)
        high2 = heapq.heappop(nums)
        return -high1 * -high2 - low1 * low2
