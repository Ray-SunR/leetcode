class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        if n == 0:
            return len(tasks)
        d = {}
        for t in tasks:
            if t not in d:
                d[t] = 0
            d[t] += 1
        pq = []
        for key in d:
            heapq.heappush(pq, (-d[key], key))
        ret = []
        temp = []
        n += 1
        original_n = n
        
        while pq or temp:
            if n == 0:
                for item in temp:
                    heapq.heappush(pq, item)
                n = original_n
                temp = []
                continue
            if len(pq) != 0:
                count, task = heapq.heappop(pq)
                count = -count
                # print('task: ' + str(task) + ' count: ' + str(count) + ' n: ' + str(n))
                ret.append(task)
                if count - 1 != 0:
                    temp.append((-(count - 1), task))
            else:
                ret.append("idle")
            n -= 1
        return len(ret)
