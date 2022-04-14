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
        t = d.copy()
        while j < len(s2):
            # print("s2[j]: " + s2[j] + " i: " + str(i) + " j: " + str(j) + " c: " + str(c))
            # print(t)
            if c == 0:
                return True
            if s2[j] not in t:
                j += 1
                i = j
                c = len(s1)
                t = d.copy()
                continue
            if s2[j] in d and t[s2[j]]:
                t[s2[j]] -= 1
                c -= 1
                j += 1
            else:
                if s2[i] in t:
                    t[s2[i]] += 1
                    c += 1
                else:
                    j += 1
                i += 1
                
                
        if c == 0:
            return True
        return False
