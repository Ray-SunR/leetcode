class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        if len(s) < 2:
            return ""
        # print(s)
        d = {}
        for i, c in enumerate(s):
            if c not in d:
                d[c] = i
        ret = ""
        valid = True
        for c in s:
            if c.lower() in d and c.upper() in d:
                continue
            else:
                valid = False
                left_longest = self.longestNiceSubstring(s[:d[c]])
                if len(left_longest) > len(ret):
                    ret = left_longest
                right_longest = self.longestNiceSubstring(s[d[c] + 1:])
                if len(right_longest) > len(ret):
                    ret = right_longest
                return ret
                # print('left: {}, right: {}'.format(left_longest, right_longest))
        
        if valid:
            return s
        else:
            return ret
            
            
