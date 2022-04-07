class Solution:
    def helper(self, candidates, target, current):
        # print('target: ' + str(target))
        # print(current)
        # print('-----')
        if target < 0:
            return
        if target == 0:
            self.ret.append(current.copy())
            return
        if not candidates:
            return
        for i in range(len(candidates)):
            val = candidates[i]
            current.append(val)
            self.helper(candidates[i:], target - val, current)
            current.pop()
        
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ret = []
        self.helper(candidates, target, [])
        return self.ret
