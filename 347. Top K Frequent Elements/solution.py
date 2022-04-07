class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for num in nums:
            if num not in freq:
                freq[num] = 0
            freq[num] += 1
        data = []
        for key in freq:
            heapq.heappush(data, (freq[key], key))
            if len(data) > k:
                heapq.heappop(data)
                
        return [val[1] for val in data]
            
