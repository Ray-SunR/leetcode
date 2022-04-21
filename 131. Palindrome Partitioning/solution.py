class Solution:
    def helper(self, s, ret):
        # print(s)
        # print(ret)
        if not s:
            self.rets.append(ret.copy())
            return
        l = 1
        while l <= len(s):
            t = s[:l]
            if t == t[::-1]:
                self.helper(s[l:], ret + [t])
            l += 1
            
    def partition(self, s: str) -> List[List[str]]:
        self.rets = []
        self.helper(s, [])
        return self.rets
