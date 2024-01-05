class Solution:
    def maxSlidingWindow(self,nums, k):
        result = []
        ret = []
        i = 0
        # [1,3,-1,-3,5,3,6,7] k = 3
        # [4]
        # [3, 3, ]
        # [1,3,1,2,0,5] k = 3
        # []
        while i < len(nums):
            # pop elements that are outside the window
            while ret and i - ret[0]  + 1 > k:
                ret.pop(0)
            
            # pop elements that are smaller than the current number because they can't possibly be the largest element in window 
            # after current push
            while ret and nums[ret[-1]] < nums[i]:
                ret.pop()
            
            ret.append(i)

            if i + 1 >= k:
                result.append(nums[ret[0]])
            # print('i: {}, ret: {}'.format(i, ret))

            i += 1
            
        return result
