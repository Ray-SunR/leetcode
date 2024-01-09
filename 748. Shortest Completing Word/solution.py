class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        d = {}
        licensePlate = licensePlate.replace(' ', '')
        licensePlate = licensePlate.lower()
        for c in licensePlate:
            if c.isdigit():
                continue
            if c not in d:
                d[c] = 0
            d[c] += 1
        # print(d)
        ret = []
        for i, word in enumerate(words):
            t = {}
            for c in word:
                if c not in t:
                    t[c] = 0
                t[c] += 1
            # print(t)
            dis = len(word)
            invalid = False
            for c in d:
                if c not in t or t[c] < d[c]:
                    invalid = True
                    break
                dis -= d[c]
            if not invalid:
                ret.append((dis, i, word))
        # print(ret)
        return sorted(ret)[0][2]
                
