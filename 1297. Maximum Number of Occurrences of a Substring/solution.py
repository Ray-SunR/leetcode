class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        l = 0
        r = 0
        d = {}
        ret = 0
        while r < len(s):
            # now we satisfy the minSize window
            if r - l + 1 >= minSize and r - l + 1 <= maxSize:
                subStr = s[l:r + 1]
                sub = set(subStr)
                if len(sub) <= maxLetters:
                    d[subStr] = d.get(subStr, 0) + 1
                    if d[subStr] > ret:
                        ret = d[subStr]
            if r - l + 1 == minSize:
                l += 1
                r += 1
            else:
                r += 1
        return ret
            
