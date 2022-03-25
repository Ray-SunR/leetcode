class Solution:
    def sanitize(self, s):
        n = ''
        for c in s:
            if (c <= 'z' and c >= 'a') or (c >= '0' and c <= '9'):
                n += c
        return n

    def isPalindrome(self, s: str) -> bool:
        s = self.sanitize(s.lower())
        r = s[::-1]
        return s == r
        
            
        
