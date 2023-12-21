class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in range(0, len(s)):
            if s[i] in ['[', '{', '(']:
                stack.append(s[i])
            elif s[i] == ']':
                if not stack:
                    return False
                c = stack.pop()
                if c != '[':
                    return False
            elif s[i] == '}':
                if not stack:
                    return False
                c = stack.pop()
                if c != '{':
                    return False
            elif s[i] == ')':
                if not stack:
                    return False
                c = stack.pop()
                if c != '(':
                    return False
        return len(stack) == 0
