class Solution:
    def checkValidString(self, s: str) -> bool:
        stk1 = []
        stk2 = []
        for i, c in enumerate(s):
            if c == '(':
                stk1.append(i)
            elif c == ')' and stk1:
                stk1.pop()
            elif c == ')' and not stk1 and stk2:
                stk2.pop()
            elif c == ')' and not stk1 and not stk2:
                return False
            else:
                stk2.append(i)
        
        if not stk1 and not stk2:
            return True
        # print(stk1)
        # print(stk2)
        # (((*
        if len(stk1) > len(stk2):
            return False
        # *( -> False
        while stk2:
            star_pos = stk2.pop()
            if stk1:
                open_pos = stk1.pop()
                if open_pos > star_pos:
                    return False
            else:
                return True
        return True
                

                
