int fib(int n) {
    int dp[31] = {};
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    int solve(int n) {
        if (n == 0 || n == 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1) + solve(n - 2);
    }

    return solve(n);
}