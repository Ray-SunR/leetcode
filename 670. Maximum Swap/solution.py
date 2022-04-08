class Solution:
    def maximumSwap(self, num: int) -> int:
        # d[i] contains the maximum number's index at starting i + 1 position
        n = list(str(num))
        d = [-inf] * len(n)
        n = [int(val) for val in n]
        i = len(n) - 2
        d[i + 1] = i + 1
        while i >= 0:
            # print(i)
            if n[d[i + 1]] >= n[i + 1]:
                d[i] = d[i + 1]
            else:
                d[i] = i + 1
            i -= 1
        # print(d)
        for i in range(len(n)):
            if n[i] < n[d[i]]:
                t = n[i]
                n[i] = n[d[i]]
                n[d[i]] = t
                return int(''.join([str(val) for val in n]))
        return int(''.join([str(val) for val in n]))
            
                
            
        
