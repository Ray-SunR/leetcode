class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        splitted = s.split(" ")
        i = 0
        w = None
        while i < len(splitted):
            if splitted[i]:
                w = splitted[i]
            i += 1
        return len(w)
