class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        cur_length = 1
        prev_length = 0
        res = 0
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cur_length += 1
            else:
                prev_length = cur_length
                cur_length = 1
            if prev_length >= cur_length:
                res += 1
        return res
