class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        chars = list(s)
        stk = []
        for i, c in enumerate(chars):
            if c == '(':
                stk.append(i)
            elif c == ')':
                if stk:
                    if chars[stk[-1]] == '(':
                        stk.pop()
                    else:
                        chars[stk[-1]] = ''
                        chars[i] = ''
                else:
                    chars[i] = ''
        while stk:
            chars[stk.pop()] = ''
        return ''.join(chars)
