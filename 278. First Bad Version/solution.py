# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def helper(self, left, right):
        mid = left + int((right - left) / 2)
        mid_p_1_bad = isBadVersion(mid + 1)
        if mid_p_1_bad and not isBadVersion(mid):
            return mid + 1
        elif mid_p_1_bad:
            return self.helper(left, mid -1)
        else:
            return self.helper(mid + 1, right)
    def firstBadVersion(self, n: int) -> int:
        return self.helper(0, n - 1)
