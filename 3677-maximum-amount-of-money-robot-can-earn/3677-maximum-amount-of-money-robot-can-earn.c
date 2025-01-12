int maximumAmount(int** coins, int coinsSize, int* coinsColSize) {
    const int INF = 1e9;
    int n = coinsSize;
    int m = *coinsColSize;
    int dp[505][505][3];
    for (int k = 0; k < 3; k++) {
        if (k > 0 && coins[0][0] < 0) {
            dp[0][0][k] = 0;
        } else {
            dp[0][0][k] = coins[0][0];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == 0 && j == 0)
                    continue;
                dp[i][j][k] = -INF;
                if (i > 0) {
                    dp[i][j][k] =
                        fmax(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                    if (k > 0) {
                        dp[i][j][k] = fmax(dp[i][j][k], dp[i - 1][j][k - 1]);
                    }
                }
                if (j > 0) {
                    dp[i][j][k] =
                        fmax(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                    if (k > 0) {
                        dp[i][j][k] = fmax(dp[i][j][k], dp[i][j - 1][k - 1]);
                    }
                }
            }
        }
    }
    int ans = dp[n - 1][m - 1][0];
    for (int i = 1; i < 3; i++) {
        ans = fmax(ans, dp[n - 1][m - 1][i]);
    }
    return ans;
}