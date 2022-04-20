class Solution:
    def helper(self, nums):
        # print(nums)
        if not nums:
            self.rets.append([])
            return
            
        self.helper(nums[1:])
        subs = self.rets.copy()
        for sub in subs:
            self.rets.append(sub + [nums[0]])
        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.rets = []
        self.helper(nums)
        return self.rets
        
