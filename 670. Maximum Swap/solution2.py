class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        # store the last index of a digit
        d = {}
        for i, c in enumerate(s):
            d[int(c)] = i
        # print(d)
        for i, c in enumerate(s):
            for digit in range(9, int(c), -1):
                # print(digit)
                if d.get(digit, -1) > i:
                    # found a digit on the right that is greater than current 'c'
                    # swap
                    t = s[i]
                    s[i] = s[d.get(digit)]
                    s[d.get(digit)] = t
                    # print("".join(s))
                    return int("".join(s))
        return num
