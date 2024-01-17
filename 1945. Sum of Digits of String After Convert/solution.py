class Solution:
    def getLucky(self, s: str, k: int) -> int:
        num = ''
        for c in s:
            num += str(ord(c) - ord('a') + 1)

        while k:
            ret = 0
            for c in str(num):
                ret += int(c)
            num = ret
            k -= 1
        return num
