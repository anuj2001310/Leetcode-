class Solution {
private:
    int solve(int n, vector<int>& dp) {
        if (n == 0 or n == 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

public:
    int fib(int n) {
        vector<int> dp(31, -1);
        dp[0] = 0;
        dp[1] = 1;
        return solve(n, dp);
    }
};