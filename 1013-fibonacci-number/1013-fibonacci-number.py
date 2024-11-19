class Solution(object):
    def solve(self, n, dp):
        if n == 0 or n == 1:
            return n
        if dp[n] != -1:
            return dp[n]
        dp[n] = self.solve(n - 1, dp) + self.solve(n - 2, dp)
        return dp[n]
        
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [-1] * 31  # Initialize the dp array with -1
        dp[0] = 0
        dp[1] = 1
        return self.solve(n, dp)