class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int lim = (m + n) >> 1;

        if (((m + n) & 1) == 0 || grid[0][0] == ')' ||
            grid[m - 1][n - 1] == '(')
            return false;

        bitset<101> mask;
        for (int i = 0; i <= lim; i++)
            mask.set(i);

        vector<bitset<101>> dp(n);

        dp[0].set(1);
        int p = 1;

        for (int j = 1; j < n; j++) {
            p += grid[0][j] == '(' ? 1 : -1;

            if (p < 0 || p > lim)
                break;

            dp[j].set(p);
        }

        p = 1;

        for (int i = 1; i < m; i++) {
            p += grid[i][0] == '(' ? 1 : -1;

            if (dp[0].none() || p < 0 || p > lim)
                dp[0].reset();
            else {
                dp[0].reset();
                dp[0].set(p);
            }

            for (int j = 1; j < n; j++) {
                dp[j] |= dp[j - 1];

                if (grid[i][j] == '(')
                    dp[j] = (dp[j] << 1) & mask;
                else
                    dp[j] >>= 1;
            }
        }

        return dp[n - 1].test(0);
    }
};