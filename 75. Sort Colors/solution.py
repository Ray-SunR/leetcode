class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        rc = 0
        wc = 0
        bc = 0
        for n in nums:
            if n == 0:
                rc += 1
            elif n == 1:
                wc += 1
            else:
                bc += 1
        for i in range(len(nums)):
            if rc:
                nums[i] = 0
                rc -= 1
            elif wc:
                nums[i] = 1
                wc -= 1
            elif bc:
                nums[i] = 2
                bc -= 1

