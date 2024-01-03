class Solution:
    def maxDepth(self, s: str) -> int:
        stk = []
        ret = -1
        for c in s:
            if c == '(':
                stk.append(c)
            elif c == ')':
                stk.pop()
            ret = max(ret, len(stk))
        return ret
