class Solution {
    private int solve(int n, int[] dp) {
        if (n == 0 || n == 1)
            return n;
            
        if (dp[n] != 0)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    public int fib(int n) {
        int[] dp = new int[31];
        dp[0] = 0;
        dp[1] = 1;
        return solve(n, dp);
    }
}