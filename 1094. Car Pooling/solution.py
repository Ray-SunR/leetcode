class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        pq = []
        car_pq = []
        for trip in trips:
            # sort based on the from position and then by to
            heapq.heappush(pq, [trip[1], trip[2], trip[0]])
        
        current = 0
        while pq:
            fr, to, capa = heapq.heappop(pq)
            if car_pq:
                # pop the passengers that are already off the car until now
                while car_pq and car_pq[0][0] <= fr:
                    t, f, cap = heapq.heappop(car_pq)
                    # print('f: {}, t: {}, cap: {} got off the car'.format(f, t, cap))
                    current -= cap
            # for car_pq, we want to know who gets off the car first
            # print('f: {}, t: {}, cap: {} got on the car'.format(fr, to, capa))
            heapq.heappush(car_pq, [to, fr, capa])
            current += capa
            if current > capacity:
                return False
        return True
                
                
                