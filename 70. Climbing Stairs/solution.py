class Solution:
    def climbStairs(self, n: int) -> int:
        # dp[i] represents the number of ways to climb to top from pos i
        # dp[i] = dp[i + 1] + dp[i + 2]
        # dp[0] is the result
        if n < 2:
            return 1
        dp = [0] * (n + 1)
        dp[n] = 1
        dp[n - 1] = 1
        dp[n - 2] = 2
        i = n - 3
        while i >= 0:
            dp[i] = dp[i + 1] + dp[i + 2]
            i -= 1
        return dp[0]
            
