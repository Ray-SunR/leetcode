class Solution:
    def dfs(self, w, words, strike):
        if strike > self.ret[0]:
            self.ret = (strike, w)
        elif strike == self.ret[0] and strike and w < self.ret[1]:
            self.ret = (strike, w)

        for c in "abcdefghijklmnopqrstuvwxyz":
            if w + c in words:
                self.dfs(w + c, words, strike + 1)

    def longestWord(self, words: List[str]) -> str:
        words = set(words)
        self.ret = (0, "")
        for w in words:
            if len(w) == 1:
                self.dfs(w, words, 1)
        return self.ret[1]
