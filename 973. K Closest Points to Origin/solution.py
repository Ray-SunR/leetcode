import heapq
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        data = []
        for point in points:
            data.append((-(point[0] * point[0] + point[1] * point[1]), point))
        heap = []
        for d in data:
            heapq.heappush(heap, d)
            if len(heap) > k:
                heapq.heappop(heap)
        ret = []
        for h in heap:
            ret.append(h[1])
        return ret
