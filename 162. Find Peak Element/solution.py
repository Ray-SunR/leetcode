class Solution:
    def find(self, nums, left, right):
        if right == left:
            return left
        if right < left:
            return -1
        mid = int(left + (right - left) / 2)
        left_val = nums[mid -1] if mid - 1 >= 0 else -math.inf
        right_val = nums[mid + 1] if mid + 1 < len(nums) else -math.inf
        if left_val < nums[mid] and right_val < nums[mid]:
            return mid
        elif left_val <= nums[mid] and right_val >= nums[mid]:
            return self.find(nums, mid + 1, right)
        else:
            return self.find(nums, left, mid - 1)
        
    def findPeakElement(self, nums: List[int]) -> int:
        return self.find(nums, 0, len(nums) - 1)
