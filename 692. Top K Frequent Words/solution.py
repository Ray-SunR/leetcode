class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        data = {}
        for word in words:
            data[word] = data.get(word, 0) + 1
        data = [(-data[word], word) for word in data]
        heapq.heapify(data)
        ret =[]
        for i in range(0, k):
            ret.append(heapq.heappop(data)[1])
        return ret
