class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) < len(str2):
            return self.gcdOfStrings(str2, str1)

        if not str1.startswith(str2):
            return ""
        
        if not str2:
            return str1
        
        return self.gcdOfStrings(str1[len(str2):], str2)
            
        
