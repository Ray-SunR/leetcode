class Solution:
    def helper(self, s: str) -> str:
        # print(s[self.i])
        s = list(s)
        num = ''
        string = ''

        while self.i < len(s):
            # print(s[self.i])
            if s[self.i] <= 'z' and s[self.i] >= 'a':
                string += s[self.i]
                self.i += 1
            elif s[self.i] >= '0' and s[self.i] <= '9':
                num += s[self.i]
                self.i +=1
            elif s[self.i] == '[':
                self.i += 1
                tempstring = self.helper(s)
                # print(s[self.i])
                num = 1 if not num else int(num)
                while num:
                    string += tempstring
                    num -= 1
                # now 'i' must point to a ']' or i is out of bound
                self.i += 1
                num = ''
            else: # ']'
                # the very last recursion must be something like:
                # [xxx]
                # OR
                # xxx
                break
        return string
                
    def decodeString(self, s: str) -> str:
        self.i = 0
        return self.helper(s)
        
                
                
