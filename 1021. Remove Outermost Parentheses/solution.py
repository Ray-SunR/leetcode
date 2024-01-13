class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        lvl = 0
        stk = []
        level_zeros = []
        for i, c in enumerate(s):
            if c == '(':
                stk.append((lvl, i, c))
                lvl += 1
            elif c == ')':
                ele = stk.pop(-1)
                if ele[0] == 0:
                    level_zeros.append(s[ele[1]:i + 1])
                lvl -= 1
        # print(level_zeros)
        ret = ''
        for ele in level_zeros:
            ret += ele[1:-1]
        return ret
            