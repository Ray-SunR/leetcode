class Solution:

    def dfs(self, word, dic):
        if word in self.memo:
            return self.memo[word]
        ret = []
        if not word:
            # This means we just found one! Insert an empty string here such that we don't exit at line 15
            # Instead, we should be building results in this case
            ret.append("")
            return ret
        
        for w in dic:
            if word.startswith(w):
                r = self.dfs(word[len(w):], dic)
                for re in r:
                    ret.append(w + ("" if len(re) == 0 else " ") + re)
        self.memo[word] = ret
        return ret
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        self.memo = {}
        return self.dfs(s, set(wordDict))

