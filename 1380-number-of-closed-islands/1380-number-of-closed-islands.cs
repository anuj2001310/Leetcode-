public class Solution {
    public int[, ] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    public int ClosedIsland(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        bool[, ] vis = new bool[n, m]; 

        void dfs(int r, int c) {
            vis[r, c] = true;
            for (var i = 0; i < 4; ++i) {
                int nr = r + dirs[i, 0];
                int nc = c + dirs[i, 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && !vis[nr, nc])
                    dfs(nr, nc);
            }
        }

        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 0 && !vis[i, j])
                        dfs(i, j);
                }
            }
        }
        var cnt = 0;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (grid[i][j] == 0 && !vis[i, j]) {
                    cnt++;
                    dfs (i, j);
                }
            }
        }
        return cnt;   
    }
}