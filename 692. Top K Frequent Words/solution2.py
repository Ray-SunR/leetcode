class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        heap = []
        d = {}
        for word in words:
            if word not in d:
                d[word] = 0
            d[word] += 1
        for word in d:
            heapq.heappush(heap, (-d[word], word))
        
        ret = []
        while k:
            ret.append(heapq.heappop(heap)[1])
            k -= 1
        return ret
