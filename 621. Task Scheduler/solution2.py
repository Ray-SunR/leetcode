class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        pq = []
        d = {}
        for task in tasks:
            if task not in d:
                d[task] = 0
            d[task] += 1
        ret = 0
        for task in d:
            heapq.heappush(pq, (-d[task], task))
        
        ret = []
        while pq:
            interval = n + 1
            temp = []
            while pq and interval:
                freq, task = heapq.heappop(pq)
                freq = -freq
                ret.append(task)
                if freq - 1:
                    temp.append((freq - 1, task))
                interval -= 1
            while temp and not pq and interval:
                ret.append('idle')
                interval -= 1
            # re-enqueue 
            for freq, task in temp:
                heapq.heappush(pq, (-freq, task))
        # print(ret)
        return len(ret)
            
            
