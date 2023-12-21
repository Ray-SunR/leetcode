class Solution:
    def helper(self, nums, l, h):
        if l == h:
            return nums[l]
        mid = l + (h - l) // 2
        if nums[mid - 1] > nums[mid] and nums[mid + 1] > nums[mid]:
            return nums[mid]
        
        if nums[l] <= nums[mid] and nums[mid] > nums[h]:
            return self.helper(nums, mid + 1, h)
        else:
            return self.helper(nums, l, mid - 1)
        
    def findMin(self, nums: List[int]) -> int:
        l = 0
        h = len(nums) - 1
        return self.helper(nums, l, h)
        
        
