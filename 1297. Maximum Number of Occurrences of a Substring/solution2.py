class Solution:
    def maxFreq(self, s, maxLetters, minSize, maxSize):
        d = {}
        ret = 0
        for i in range(len(s)):
            if i + minSize > len(s):
                break
            substr = s[i : i + minSize]
            size = len(set(substr))
            if size <= maxLetters:
                if substr not in d:
                    d[substr] = 0
                d[substr] += 1
                ret = max(ret, d[substr])
        return ret
                
