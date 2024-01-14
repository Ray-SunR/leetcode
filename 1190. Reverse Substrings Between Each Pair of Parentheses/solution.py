class Solution:
    def reverseParentheses(self, s: str) -> str:
        stk = []
        for c in s:
            if c != ')':
                stk.append(c)
            else:
                tmp = ''
                while stk and stk[-1] != '(':
                    tmp = tmp + stk.pop()[::-1]
                stk.pop()
                stk.append(tmp)
        # (abc)abc -> cbaabc
        return ''.join(stk)