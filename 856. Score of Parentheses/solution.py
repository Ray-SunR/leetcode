class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ret = 0
        stk = []
        for c in s:
            if c == '(':
                stk.append(c)
            elif c == ')':
                if stk[-1] == '(':
                    stk.pop(-1)
                    stk.append(1)
                else:
                    # if it's a number
                    # ((())) == 4
                    num = 0
                    while stk[-1] != '(':
                        num += stk.pop(-1)
                    stk.pop(-1)
                    stk.append(num * 2)
        
        while stk:
            ret += stk.pop()
        return ret


# [(, 2, 2,]