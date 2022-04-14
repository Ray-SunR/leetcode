class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # window. Check if a window s2 contains all chars in s1
        d = {}
        for c in s1:
            if c not in d:
                d[c] = 0
            d[c] += 1

        i = 0
        j = 0
        c = len(s1)
        while j < len(s2):
            # print("s2[j]: " + s2[j] + " i: " + str(i) + " j: " + str(j))
            # print(d)
            if c == 0:
                return True
            if s2[j] in d and d[s2[j]]:
                c -= 1
                d[s2[j]] -= 1
                j += 1
            else:
                if s2[i] in d:
                    c += 1
                    d[s2[i]] += 1
                else:
                    j += 1
                i += 1
        if c == 0:
            return True
        return False
