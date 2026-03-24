class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        int n = grid.length, m = grid[0].length;

        var ans = new int[n][m];
        for (int i = 0; i < n; ++i)
            Arrays.fill(ans[i], 1);

        long left = 1, right = 1;
        final int MOD = 12345;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = (int) (ans[i][j] * left) % MOD;
                left = (left * grid[i][j]) % MOD;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                ans[i][j] = (int) (ans[i][j] * right) % MOD;
                right = (right * grid[i][j]) % MOD;
            }
        }

        return ans;
    }
}