class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stk = []
        removes = []
        for i in range(len(s)):
            if s[i] == ')':
                if stk and stk[-1][0] == '(':
                    stk.pop()
                else:
                    removes.append(i)
            elif s[i] == '(':
                stk.append((s[i], i))
            
        while stk:
            item = stk.pop()
            removes.append(item[1])
        
        data = list(s)
        for remove in removes:
            data[remove] = ''
        return ''.join(data)
