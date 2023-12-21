class Solution:
    def helper(self, nums, i, n):
        if not nums:
            self.ret += 1
            return
        
        for num in range(1, n + 1):
            if num not in nums:
                continue
            if (num % i == 0 or i % num == 0):
                nums.remove(num)
                self.helper(nums, i + 1, n)
                nums.add(num)
        return False
    def countArrangement(self, n: int) -> int:
        nums = set([i for i in range(1, n + 1)])
        self.ret = 0
        # for i in range(1, n + 1):
        self.helper(nums, 1, n)
        return self.ret
                    
        
