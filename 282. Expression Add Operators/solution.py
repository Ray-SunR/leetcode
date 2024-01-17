class Solution:
    def helper(self, num, i, total, prev, ret, target):
        if i == len(num) and total == target:
            self.ret.append(ret)
            return
        elif i >= len(num):
            return
        
        for j in range(i, len(num) + 1):
            if j > i and num[i] == '0':
                break
            val = int(num[i:j + 1])
            if i == 0:
                self.helper(num, j + 1, val, val, str(val), target)
            else:
                # '+'
                self.helper(num, j + 1, total + val, val, ret + '+' + str(val), target)
                # '-'
                self.helper(num, j + 1, total - val, -val, ret + '-' + str(val), target)
                # '*'
                self.helper(num, j + 1, total - prev + prev * val, prev * val, ret + '*' + str(val), target) 
        
    def addOperators(self, num: str, target: int) -> List[str]:
        self.ret = []
        self.helper(num, 0, 0, 0, '', target)
        return self.ret