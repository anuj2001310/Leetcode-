class Solution {
    int[][] dirs = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

    public void dfs(int r, int c, char[][] grid, boolean[][] vis, int n, int m) {
        vis[r][c] = true;

        for (int[] dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1')
                dfs(nr, nc, grid, vis, n, m);
        }
        return;
    }

    public int numIslands(char[][] grid) {
        int n = grid.length, m = grid[0].length;
        int cnt = 0;
        boolean[][] vis = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
}