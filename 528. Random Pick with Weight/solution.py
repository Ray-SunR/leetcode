from bisect import bisect_left
import random
class Solution:

    def __init__(self, w: List[int]):
        self.prefix_sum = [0] * len(w)
        previous = 0
        for i in range(len(w)):
            self.prefix_sum[i] = w[i] + previous
            previous = self.prefix_sum[i]
        # [1, 3, 4,] -> [1, 4, 8]
        # generate a random number between 1 and prefix_sum[-1] and figure out the insert position, e.g 2
        # should fall in between of 1 and 3, thus, should return 3's index which is 2.

    def pickIndex(self) -> int:
        x = random.randint(1, self.prefix_sum[-1])
        # Find the leftmost value greater or equal to x
        i = bisect_left(self.prefix_sum, x)
        # i indicates the insertion position
        return i
        
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
