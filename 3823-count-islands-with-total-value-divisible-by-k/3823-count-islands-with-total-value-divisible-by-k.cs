public class Solution {
    public int CountIslands(int[][] grid, int k) {
        int n = grid.Length;
        int m = grid[0].Length;
        bool[, ] vis = new bool[n, m];

        long dfs (int r, int c) {
            if (r >= n || r < 0 || c >= m || c < 0 || vis[r, c] || grid[r][c] == 0)
                return 0;

            vis[r, c] = true;
            long sum = grid[r][c];
            sum += dfs (r - 1, c);
            sum += dfs (r, c + 1);
            sum += dfs (r + 1, c);
            sum += dfs (r, c - 1);
            
            return sum;
        }
        
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i, j] && grid[i][j] > 0) {
                    long val = dfs (i, j);
                    if (val % k == 0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
}