class Solution:
    def shortestToChar1(self, s: str, c: str) -> List[int]:
        indexes = []
        for i, char in enumerate(s):
            if char == c:
                indexes.append(i)

        i = 0
        ret = [float(inf)] * len(s)
        while i < len(s):
            for idx in indexes:
                ret[i] = min(ret[i], abs(idx - i))
            i += 1
        return ret
    
    def shortestToChar(self, s: str, c: str) -> List[int]:
        # two passes
        ret = [float(inf)] * len(s)
        for i, char in enumerate(s):
            if char == c:
                ret[i] = 0 
            elif i - 1 >= 0:
                ret[i] = ret[i - 1] + 1
            else:
                ret[i] = len(s)
        
        print(ret)

        # second pass from right to left
        j = len(s) - 2
        while j >= 0:
            ret[j] = min(ret[j + 1] + 1, ret[j])
            j -= 1
        return ret

