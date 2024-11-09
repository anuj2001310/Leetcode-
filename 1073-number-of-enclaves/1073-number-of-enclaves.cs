public class Solution {
    public int NumEnclaves(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        bool[, ] vis = new bool[n, m];

        int[, ] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        void dfs(int r, int c) {
            vis[r, c] = true;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i, 0];
                int nc = c + dirs[i, 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr, nc])
                    dfs(nr, nc);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1 && !vis[i, j]) {
                        dfs(i, j);
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i, j])
                    ++cnt;
            }
        }
        return cnt;
    }
}