from typing import (
    List,
)

class Solution:
    """
    @param words: a list of words
    @param word1: a string
    @param word2: a string
    @return: the shortest distance between word1 and word2 in the list
    """
    def shortest_distance(self, words: List[str], word1: str, word2: str) -> int:
        # first pass from left to right
        ret = [0] * len(words)
        for i, w in enumerate(words):
            if w == word1:
                ret[i] = 0
            elif i - 1 >= 0:
                ret[i] = ret[i - 1] + 1
            else:
                ret[i] = len(words)
        
        # second pass from right to left
        i = len(words) - 1
        dis = float('inf')
        while i >= 0:
            if i + 1 < len(words):
                ret[i] = min(ret[i + 1] + 1, ret[i])
            if words[i] == word2:
                dis = min(dis, ret[i])
            i -= 1
        return dis
            

