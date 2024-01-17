class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        # 5 -> 0 , 1, 2, 3, 4
        first = s[0:len(s) // 2]
        second = s[len(s) // 2 + 1 if len(s) % 2 == 1 else len(s) // 2:]
        # print('fifrst: {}, second: {}'.format(first, second))
        c1 = 0
        for c in first:
            if c in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
                c1 += 1
        for c in second:
            if c in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
                c1 -= 1
        return c1 == 0