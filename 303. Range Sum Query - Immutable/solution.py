lass NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        # key would be the index, value would be an array containing sum starting from the value to the value 
        # total sum: -3
        # [-2, 0, 3, -5, 2, -1]
        # left sum
        # [0, -2, -2, 1, -6, -4]
        # right sum
        # [-1, -1, -4, 1, -1, 0]
        # [0, 2] -> left sum of 0: 0, right sum of 2: -4, sum([0,2]) = total_sum - left_sum - right_sum = -3 - 0 - (-4) = 1
        # [2, 5] -> left sum of 2: -2, right sum of 5: 0, sum([2,5]) = total_sum - left_sum - right_sum = -3 - (-2) - 0 = -1
        # [0, 5] -> -3 - 0 - 0 = -3
        '''
        0: [-2, -2, 1, -4, -2, -3]
        1: [0,   3, -2, 0, -1]
        2: [3,  -2, 0, -1]
        3: [-5, -3, -4]
        4: []
        '''
        self.total_sum = 0
        self.left_sum = [0] * len(nums)
        self.right_sum = [0] * len(nums)
        for i, num in enumerate(nums):
            self.left_sum[i] = self.total_sum
            self.total_sum += num
        
        right_sum = 0
        i = len(nums) - 1
        while i >= 0:
            self.right_sum[i] = right_sum
            right_sum += nums[i]
            i -= 1
        # print(self.left_sum)
        # print(self.right_sum)

    def sumRange(self, left: int, right: int) -> int:
        return self.total_sum - self.left_sum[left] - self.right_sum[right]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
