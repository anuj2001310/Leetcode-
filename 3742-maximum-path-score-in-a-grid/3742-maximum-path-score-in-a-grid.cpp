class Solution {
public:
    int m, n;
    static int dp[201][201][1001];
    int f(int r, int c, int k, vector<vector<int>>& g) {
        if (k < 0)
            return -1e8;
        if (r == m - 1 && c == n - 1) {
            k -= ((g[r][c] == 0) ? 0 : 1);
            if (k >= 0)
                return g[r][c];
            return -1e8;
        }
        if (dp[r][c][k] != INT_MIN)
            return dp[r][c][k];
        int down = -1e8, right = -1e8, score = g[r][c];
        int cost = score > 0 ? 1 : 0;
        if (r != m - 1) {
            down = score + f(r + 1, c, k - cost, g);
        }
        if (c != n - 1) {
            right = score + f(r, c + 1, k - cost, g);
        }
        return dp[r][c][k] = max(down, right);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int l = 0; l <= k; l++) {
                    dp[i][j][l] = INT_MIN;
                }
            }
        }
        int ans = f(0, 0, k, grid);
        return ans < 0 ? -1 : ans;
    }
};
int Solution::dp[201][201][1001];