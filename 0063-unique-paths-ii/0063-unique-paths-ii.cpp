class Solution {
private:
    long long solve(int i, int j, vector<vector<long long>>& dp,
              vector<vector<int>>& grid) {
        if (i == 0 and j == 0)
            return 1;
        if (i < 0 or j < 0 or grid[i][j])
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long t = solve(i - 1, j, dp, grid);
        long long l = solve(i, j - 1, dp, grid);
        return dp[i][j] = t + l;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0])
            return 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
        return solve(n - 1, m - 1, dp, grid);
    }
};