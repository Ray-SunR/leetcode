class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        minheap = []
        for num in nums:
            if len(minheap) == k and minheap[0] < num:
                heapq.heappop(minheap)
                heapq.heappush(minheap, num)
            elif len(minheap) < k:
                heapq.heappush(minheap, num)
        
        return minheap[0]
