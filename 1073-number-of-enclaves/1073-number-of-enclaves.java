class Solution {
    static int[][] dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    private void dfs(int r, int c, int[][] grid, boolean[][] vis,
            int n, int m) {
        vis[r][c] = true;
        for (int i = 0; i < dir.length; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 &&
                    !vis[nr][nc]) {
                dfs(nr, nc, grid, vis, n, m);
            }
        }
    }

    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][] vis = new boolean[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1 && !vis[i][j]) {
                        dfs(i, j, grid, vis, n, m);
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j])
                    ++cnt;
            }
        }
        return cnt;
    }
}