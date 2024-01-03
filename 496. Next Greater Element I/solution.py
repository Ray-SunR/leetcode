class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stk = []
        ret = [-1] * len(nums2)
        idx = {}
        for i, num in enumerate(nums2):
            idx[num] = i
            while stk and nums2[stk[-1]] < num:
                ret[stk.pop()] = num
            stk.append(i)
        
        return [ret[idx[num]] for num in nums1]
