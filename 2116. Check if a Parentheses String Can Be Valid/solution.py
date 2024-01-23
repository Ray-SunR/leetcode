class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 == 1:
            return False
        op, cl, var = 0, 0, 0
        for i, c in enumerate(s):
            if locked[i] == '0':
                var += 1
            elif s[i] == '(':
                op += 1
            else:
                cl += 1
            if cl - op > var:
                return False
        
        # ))((, 0011
        op, cl, var = 0, 0, 0
        i = len(s) - 1
        while i >= 0:
            if locked[i] == '0':
                var += 1
            elif s[i] == '(':
                op += 1
            else:
                cl += 1
            i -= 1
            if op - cl > var:
                return False
        return True