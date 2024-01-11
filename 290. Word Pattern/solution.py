class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        d = {}
        w = {}
        i = 0
        j = 0
        words = s.split(' ')
        if len(words) != len(pattern):
            return False
        while i < len(pattern) and j < len(words):
            if pattern[i] in d:
                if d[pattern[i]] != words[j]:
                    return False
            elif words[j] in w:
                if w[words[j]] != pattern[i]:
                    return False
            else:
                d[pattern[i]] = words[j]
                w[words[j]] = pattern[i]
            i += 1
            j += 1
        # print('i: {}, j: {}'.format(i, j))
        return True
