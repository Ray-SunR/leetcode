class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        num1 = list(num1)
        num2 = list(num2)
        i = len(num1) - 1
        j = len(num2) - 1
        carry = 0
        ret = ""
        while i >= 0 and j >= 0:
            vi = int(num1[i])
            vj = int(num2[j])
            val = vi + vj + carry
            carry = int(val / 10)
            remainder = val % 10
            ret = str(remainder) + ret
            i -= 1
            j -= 1
        
        if i < 0:
            while j >= 0:
                # print('nums2[j]: ' + num2[j] + ' carry: ' + str(carry))
                v = int(num2[j]) + carry
                carry = int(v / 10)
                remainder = v % 10
                # print('remainder: ' + str(remainder) + ' carry: ' + str(carry))
                ret = str(remainder) + ret
                j -= 1
            if carry:
                ret = str(carry) + ret
        else:
            while i >= 0:
                v = int(num1[i]) + carry
                carry = int(v / 10)
                remainder = v % 10
                ret = str(remainder) + ret
                i -= 1
            if carry:
                ret = str(carry) + ret
        return ret
        
        
