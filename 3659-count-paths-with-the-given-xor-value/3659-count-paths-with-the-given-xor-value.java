class Solution {
    final int MOD = (int) 1e9 + 7;

    private int help(int[][] grid, int n, int m, int val, int k, int[][][] dp) {
        if (n == 0 && m == 0) {
            if ((val ^ grid[0][0]) == k)
                return 1;
            else
                return 0;
        }
        if (n < 0 || m < 0)
            return 0;
        if (dp[n][m][val] != -1)
            return dp[n][m][val];
        int up = help(grid, n - 1, m, val ^ grid[n][m], k, dp);
        int left = help(grid, n, m - 1, val ^ grid[n][m], k, dp);

        return dp[n][m][val] = (up + left) % MOD;

    }

    public int countPathsWithXorValue(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;
        int[][][] dp = new int[n][m][16];
        for (int r = 0; r < n; r++)
            for (int s = 0; s < m; s++)
                for (int t = 0; t < 16; t++)
                    dp[r][s][t] = -1;

        return help(grid, n - 1, m - 1, 0, k, dp);
    }
}