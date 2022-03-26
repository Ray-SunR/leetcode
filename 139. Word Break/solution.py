class Solution:
    def check(self, s, wordDict):
        l = 1
        if s in self.memo:
            return self.memo[s]
        if not s:
            return True
        while l <= len(s):
            if s[:l] in wordDict and self.check(s[l:], wordDict):
                self.memo[s] = True
                return True
            l += 1
        self.memo[s] = False
        return False
    
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.memo = {}
        return self.check(s, wordDict)

