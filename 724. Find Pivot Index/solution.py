class Solution:        
    def pivotIndex(self, nums: List[int]) -> int:
        leftSum = 0
        rightSum = 0
        self.leftSum = [0] * len(nums)
        self.rightSum = [0] * len(nums)
        for idx in range(len(nums)):
            self.leftSum[idx] = leftSum
            leftSum += nums[idx]
        idx = len(nums) - 1
        while idx >=0:
            self.rightSum[idx] = rightSum
            rightSum += nums[idx]
            idx -= 1
        # print(self.leftSum)
        # print(self.rightSum)
        for i in range(len(nums)):
            if self.leftSum[i] == self.rightSum[i]:
                return i
        return -1
        
