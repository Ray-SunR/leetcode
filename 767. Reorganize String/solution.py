class Solution:
    def reorganizeString(self, s: str) -> str:
        d = {}
        for c in s:
            if c not in d:
                d[c] = 0
            d[c] += 1
        pq = []
        for c in d:
            heapq.heappush(pq, (-d[c], c))
        
        ret = ''
        while pq:
            freq, c = heapq.heappop(pq)
            ret += c
            freq = -freq
            freq -= 1

            nfreq, nc = 0, ''
            if pq:
                nfreq, nc = heapq.heappop(pq)
                nfreq = -nfreq
                ret += nc
                nfreq -= 1
            elif not pq and freq > 0:
                return ""

            if freq > 0:
                heapq.heappush(pq, (-freq, c))
            if nfreq > 0:
                heapq.heappush(pq, (-nfreq, nc))
                
        return ret
