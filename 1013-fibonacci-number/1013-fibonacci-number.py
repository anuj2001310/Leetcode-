class Solution:
    def fib(self, n: int) -> int:
        dp = [-1] * 31
        dp[0] = 0
        dp[1] = 1
        def solve(n):
            if n == 0 or n == 1:
                return n
            if dp[n] != -1:
                return dp[n]
            
            dp[n] = solve(n - 1) + solve(n - 2)
            return dp[n]
        
        return solve(n)