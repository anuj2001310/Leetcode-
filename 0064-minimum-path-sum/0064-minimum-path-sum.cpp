class Solution {
private:
    int backtrack(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 and j == 0)
            return grid[i][j];
        if (i < 0 or j < 0)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = grid[i][j] + backtrack(i, j - 1, grid, dp);
        int up = grid[i][j] + backtrack(i - 1, j, grid, dp);
        return dp[i][j] = fmin(left, up);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return backtrack(n - 1, m - 1, grid, dp);
    }
};