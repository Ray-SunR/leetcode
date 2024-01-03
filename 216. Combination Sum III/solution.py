class Solution:
    def helper(self, current_arr, current_sum, used_nums, k, n):
        if current_sum == n and len(current_arr) == k:
            self.ret.add(tuple(sorted(current_arr)))
            return
        elif len(current_arr) == n:
            return
        
        for i in range(1, 10):
            if i not in used_nums:
                used_nums.add(i)
                self.helper(current_arr + [i], current_sum + i, used_nums, k, n)
                used_nums.remove(i)
        
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.ret = set()
        self.helper([], 0, set(), k, n)
        return list(self.ret)
