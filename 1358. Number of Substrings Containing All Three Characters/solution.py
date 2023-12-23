class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        d = {'a': 0, 'b': 0, 'c': 0}
        ret = 0
        i = 0
        j = 0
        while j < len(s):
            d[s[j]] += 1
            while all(d[c] >= 1 for c in 'abc'):
                ret += len(s) - j
                d[s[i]] -= 1
                i += 1
            j += 1
        return ret
