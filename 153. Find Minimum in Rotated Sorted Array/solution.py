class Solution:
    def helper(self, nums, l, r):
        if l > r:
            return
        if l == r:
            return nums[l]
        mid = l + int((r - l) / 2)
        # print("mid: " + str(mid) + " l: " + str(l) + " r: " + str(r))
        if mid + 1 < len(nums) and nums[mid + 1] < nums[mid]:
            return nums[mid + 1]
        if nums[mid] > nums[-1]:
            return self.helper(nums, mid + 1, r)
        else:
            return self.helper(nums, l, mid)
    def findMin(self, nums: List[int]) -> int:
        return self.helper(nums, 0, len(nums) - 1)
