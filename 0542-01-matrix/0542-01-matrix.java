class Solution {
    static int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    public int[][] updateMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        int[][] dist = new int[n][m];
        
        Queue<int[]> q = new ArrayDeque<>();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    vis[i][j] = true;
                    q.offer (new int[] {i, j, 0});
                }
            }
        }
        
        while (!q.isEmpty()) {
            int r = q.peek()[0];
            int c = q.peek()[1];
            int val = q.peek()[2];
            q.poll();
            
            dist[r][c] = val;
            for (int i = 0; i < dirs.length; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.offer (new int[] {nr, nc, val + 1});
                }
            }
        }
        return dist;
    }
}