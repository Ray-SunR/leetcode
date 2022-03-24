class Solution:
    def isPalindrome(self, s):
        left = 0
        right = len(s) - 1
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
    def validPalindrome(self, s: str) -> bool:
        # left, right pointers, compare, if match, both decrement, if not, either remove left or right
        left = 0
        right = len(s) - 1
        while left < right:
            if s[left] != s[right]:
                # remove left, remove right
                return self.isPalindrome(s[left + 1:right + 1]) or self.isPalindrome(s[left:right])
            else:
                left += 1
                right -= 1
        return True
        
