from typing import (
    List,
)

class Solution:
    def is_feasible(self, cut, ribbons, k):
        d = {}
        for ribbon in ribbons:
            intpart = ribbon // cut
            remainder = ribbon % cut
            d[cut] = d.get(cut, 0) + intpart
            d[remainder] = d.get(remainder, 0) + 1
        for i in d:
            if d[i] >= k:
                return True
        # if cut == 5:
            # print('mid: {}, d: {}'.format(cut, d))
        return False
            
    """
    @param ribbons: An integer array
    @param k: Number of ribbons of the same length
    @return: Maximum length of ribbons
    """
    def max_length(self, ribbons: List[int], k: int) -> int:
        l, h = 1, max(ribbons)
        ret = 0
        while l <= h:
            mid = l + (h - l) // 2
            if self.is_feasible(mid, ribbons, k):
                # print('mid: {}, l: {}, h: {} feasible'.format(mid, l, h))
                ret = max(ret, mid)
                l = mid + 1
            else:
                h = mid - 1
        return ret
