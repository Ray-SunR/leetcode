class Solution:
    def isPalindrome(self, s):
        print(s)
        b = 0
        e = len(s) - 1
        while b < e:
            if s[b] != s[e]:
                return False
            b = b + 1
            e = e - 1
        return True
    
    def validPalindrome(self, s: str) -> bool:
        b = 0
        e = len(s) - 1
        while b < e:
            if s[b] != s[e]:
                return self.isPalindrome(s[b+1:e+1]) or self.isPalindrome(s[b:e])
            b = b + 1
            e = e - 1
        return True
