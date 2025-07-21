class Solution {
    static int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private long bfs (int s, int e, int[][] grid, boolean[][] vis) {
        Queue<int[]> q = new ArrayDeque<>();   
        q.offer (new int[] {s, e});
        vis[s][e] = true;
        long ans = 0;
        int n = grid.length, m = grid[0].length;
        
        while (!q.isEmpty()) {
            int r = q.peek()[0];
            int c = q.peek()[1];
            q.poll();
            
            ans += grid[r][c];
            
            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] > 0) {
                    q.offer (new int[] {nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
        return ans;
    }
    
    public int countIslands(int[][] grid, int k) {
        int n = grid.length, m = grid[0].length;
        boolean[][] vis = new boolean[n][m];

        int curr = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    long val = bfs (i, j, grid, vis);
                    if (val % k == 0)
                        curr++;
                }
            }
        }
        return curr;
    }
}