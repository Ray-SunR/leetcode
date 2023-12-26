class Solution:
    def isFeasible(self, weights, capacity, days):
        i = 0
        total_capacity = 0
        days_needed = 0
        while i < len(weights):
            if weights[i] > capacity:
                return False
            if weights[i] + total_capacity > capacity:
                total_capacity = weights[i]
                days_needed += 1
            else:
                total_capacity += weights[i]
            i += 1
        # print('days_needed: {}, i: {}'.format(days_needed, i))
        if days_needed + 1 <= days and i == len(weights):
            return True
        return False

    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l, h = min(weights), sum(weights)
        while l < h:
            mid = l + (h - l) // 2
            if self.isFeasible(weights, mid, days):
                # print('capacity: {} is feasible, l: {}, h: {}'.format(mid, l, h))
                h = mid
            else:
                # print('capacity: {} is not feasible, l: {}, h: {}'.format(mid, l, h))
                l = mid + 1
        return l
        
