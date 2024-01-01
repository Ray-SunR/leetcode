from typing import (
    List,
)

class Solution:
    """
    @param words: the array of string means the list of words
    @param order: a string indicate the order of letters
    @return: return true or false
    """
    def is_alien_sorted(self, words: List[str], order: str) -> bool:
        # write your code here.
        d = {}
        for i, c in enumerate(order):
            d[c] = i
        
        def compare(x, y):
            if x == y:
                return 0

            i = 0
            while i < len(x) and i < len(y):
                if d[x[i]] < d[y[i]]:
                    return -1
                elif d[x[i]] > d[y[i]]:
                    return 1
                
                i += 1
            if i == len(x):
                return -1
            else:
                return 1
            
        i = 1
        while i < len(words):
            if compare(words[i - 1], words[i]) > 0:
                return False
            i += 1
        return True
        
