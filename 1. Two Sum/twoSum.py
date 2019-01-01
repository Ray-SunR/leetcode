class Solution(object):
    def twoSum(self, nums, target):
        """
            :type nums: List[int]
            :type target: int
            :rtype: List[int]
            """
        hash = {}
        for i in range(0, len(nums)):
            hash[target - nums[i]] = i
        
        for i in range(0, len(nums)):
            if nums[i] in hash and hash[nums[i]] != i:
                return [hash[nums[i]], i]

