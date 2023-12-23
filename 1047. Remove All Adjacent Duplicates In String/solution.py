class Solution:
    
    def removeDuplicates(self, s: str) -> str:
        sta = []
        i = 0
        while i < len(s):
            # print("i: {}, sta: {}".format(i, sta))
            while i < len(s) and sta and sta[-1] == s[i]:
                sta.pop()
                i += 1
            
            if i < len(s):
                sta.append(s[i])
            else:
                break
            i += 1
            
        return ''.join(sta)
