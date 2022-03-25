class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        # stack? 
        left = []
        count = 0
        for c in s:
            if c == '(':
                left.append('(')
            else:
                if left and left[-1] == '(':
                    left.pop()
                else:
                    count += 1
        if left:
            return len(left) + count
        return count
