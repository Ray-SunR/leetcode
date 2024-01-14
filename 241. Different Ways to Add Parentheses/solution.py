class Solution:
    def helper(self, expression):
        # print(expression)
        if expression.isdigit():
            return [int(expression)]
        ret = []
        for i, c in enumerate(expression):
            if c in ['-', '+', '*']:
                left = self.helper(expression[:i])
                right  = self.helper(expression[i + 1:])
                for num_left in left:
                    for num_right in right:
                        if c == '-':
                            ret.append(num_left - num_right)
                        elif c == '+':
                            ret.append(num_left + num_right)
                        else:
                            ret.append(num_left * num_right)
        return ret
    def diffWaysToCompute(self, expression: str) -> List[int]:
        return self.helper(expression)
        