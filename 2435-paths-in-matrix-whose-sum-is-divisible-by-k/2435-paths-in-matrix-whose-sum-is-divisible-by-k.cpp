class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m][K];
        memset(dp, 0, sizeof(dp));
        dp[0][0][grid[0][0] % K] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = !i; j < m; j++) {
                int val = grid[i][j];
                for (int k = 0; k < K; k++) {
                    int idx = (val + k) % K;
                    if (j)
                        dp[i][j][idx] = (dp[i][j][idx] + dp[i][j - 1][k]) % MOD;
                    if (i)
                        dp[i][j][idx] = (dp[i][j][idx] + dp[i - 1][j][k]) % MOD;
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};