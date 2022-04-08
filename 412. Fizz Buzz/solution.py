class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        i = 1
        ret = [None] * n
        while i <= n:
            if i % 5 == 0 and i % 3 == 0:
                ret[i - 1] = "FizzBuzz"
            elif i % 5 == 0:
                ret[i - 1] = "Buzz"
            elif i % 3 == 0:
                ret[i - 1] = "Fizz"
            else:
                ret[i - 1] = str(i)
            i += 1
        return ret
