class Solution {
private:
    int memo(int r, int c, vector<vector<int>>& dp, int m, int n) {
        if (r >= m or c >= n)
            return 0;

        if (r == m - 1 and c == n - 1)
            return 1;

        if (dp[r][c] != -1)
            return dp[r][c];
        
        int right = memo(r, c + 1, dp, m, n);
        int down = memo(r + 1, c, dp, m, n);
        return dp[r][c] = right + down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memo(0, 0, dp, m, n);
    }
};