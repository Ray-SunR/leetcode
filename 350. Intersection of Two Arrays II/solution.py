class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) < len(nums2):
            return self.intersect(nums2, nums1)
        d = {}
        for n in nums1:
            if n not in d:
                d[n] = 0
            d[n] += 1
        ret = []
        for n in nums2:
            if n in d and d[n]:
                d[n] -= 1
                ret.append(n)
        return ret
