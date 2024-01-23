class Solution:
    def minInsertions(self, s: str) -> int:
        stk = []
        cnt = 0
        i = 0
        while i < len(s):
            c = s[i]
            if c == '(':
                stk.append(c)
            elif c == ')':
                if i + 1 < len(s) and s[i + 1] == ')':
                    if stk:
                        stk.pop(-1)
                        # '())'
                        # perfect
                    else:
                        # '))'
                        # need one extra '('
                        cnt += 1
                    i += 2
                    continue
                else:
                    if stk:
                        # '()('
                        # need one extra ')'
                        stk.pop(-1)
                        cnt += 1
                    else:
                        # ')('
                        # need one '(' and one ')'
                        cnt += 2
            i += 1
        return cnt + len(stk) * 2
            

        

                