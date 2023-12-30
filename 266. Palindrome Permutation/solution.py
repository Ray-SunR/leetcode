class Solution:
    """
    @param s: the given string
    @return: if a permutation of the string could form a palindrome
    """
    def can_permute_palindrome(self, s: str) -> bool:
        # write your code here
        d = {}
        for c in s:
            if c not in d:
                d[c] = 0
            d[c] += 1
        seen_odd = False
        for c in d:
            if d[c] % 2 == 1:
                if seen_odd:
                    return False
                seen_odd = True
        return True
                
