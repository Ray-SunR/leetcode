class Solution:
    def getStep(self, num):
        step = 0
        while num != 1:
            if num % 2 == 0:
                num //= 2
            else:
                num = 3 * num + 1
            step += 1
        return step
    def getKth(self, lo: int, hi: int, k: int) -> int:
        nums = [val for val in range(lo, hi + 1)]
        steps = [(self.getStep(val), val) for val in nums]
        heapq.heapify(steps)
        i = 0
        ret = None
        while i != k:
            _, ret = heapq.heappop(steps)
            i += 1
        return ret