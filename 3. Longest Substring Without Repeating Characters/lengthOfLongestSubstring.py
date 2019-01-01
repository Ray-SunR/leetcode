class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
            :type s: str
            :rtype: int
            """
        hash = set()
        result = 0
        begin = 0
        i = 0
        while (i < len(s)):
            if s[i] not in hash:
                hash.add(s[i])
                result = result if result > len(hash) else len(hash)
                i = i + 1
            else:
                hash.remove(s[begin])
                begin = begin + 1
        return result
