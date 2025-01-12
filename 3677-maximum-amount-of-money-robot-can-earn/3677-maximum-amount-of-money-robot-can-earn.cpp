class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = ssize(coins), m = ssize(coins[0]), inf = 1e9;
        vector dp(n + 1, vector(m + 1, vector(3, -inf)));
        dp[0][1].assign(3, 0), dp[1][0].assign(3, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                auto c = coins[i][j];
                dp[i + 1][j + 1][0] =
                    max(dp[i + 1][j][0] + c, dp[i][j + 1][0] + c);
                dp[i + 1][j + 1][1] =
                    max({dp[i + 1][j][1] + c, dp[i][j + 1][1] + c,
                         dp[i + 1][j][0], dp[i][j + 1][0]});
                dp[i + 1][j + 1][2] =
                    max({dp[i + 1][j][2] + c, dp[i][j + 1][2] + c,
                         dp[i + 1][j][1], dp[i][j + 1][1]});
            }
        }

        return ranges::max(dp[n][m]);
    }
};