from typing import (
    List,
)

class Solution:
    def helper(self, d, current_str, ret):
        if len(current_str) == len(self.s):
            ret.add(current_str)
            return
        if current_str in ret:
            return
        
        # aabbcc
        # [cbaabc, abccba, baccab]
        for c in d:
            if d[c] == 0:
                continue
            new_str = c + current_str + c
            d[c] -= 2
            self.helper(d, new_str, ret)
            d[c] += 2
            
            
        
    """
    @param s: the given string
    @return: all the palindromic permutations (without duplicates) of it
             we will sort your return value in output
    """
    def generate_palindromes(self, s: str) -> List[str]:
        self.s = s
        # write your code here
        d = {}
        for c in s:
            if c not in d:
                d[c] = 0
            d[c] += 1
        
        odd_c = None
        for c in d:
            if d[c] != 0 and d[c] % 2 != 0:
                if odd_c:
                    return []
                odd_c = c
        ret = set()
        if odd_c:
            d[odd_c] -= 1
            self.helper(d, odd_c, ret)
        else:
            self.helper(d, "", ret)
        return list(ret)
            
        
