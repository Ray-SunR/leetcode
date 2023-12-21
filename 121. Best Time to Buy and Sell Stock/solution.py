class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        data = []
        ret = 0
        for price in prices:
            if data and data[0] < price:
                ret = max(price - data[0], ret)
            heapq.heappush(data, price)
        return ret
