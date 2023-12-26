class Solution:
    def isFeasible(self, piles, speed, k):
        time_remaining = k
        i = 0
        total = 0
        while time_remaining >= 0 and i < len(piles):
            # print('k: {}, piles[i] // speed: {}, time_remaining: {}, i: {}'.format(k, piles[i] // speed, time_remaining, i))
            time_remaining = time_remaining - ((piles[i] - 1) // speed + 1)
            i += 1
        # print('time_remaining: {}, i: {}'.format(time_remaining, i))
        if time_remaining >= 0 and i == len(piles):
            return True
        return False
    def minEatingSpeed(self, piles: List[int], k: int) -> int:

        
        l = 1
        h = max(piles)
        while l < h:
            mid = l + (h - l) // 2
            # print('l: {}, h: {}, mid: {}'.format(l, h, mid))
            if self.isFeasible(piles, mid, k):
                # print('mid: {} is feasible'.format(mid))
                h = mid
            else:
                # print('mid: {} is not feasible'.format(mid))
                l = mid + 1
        return l
                    
                
