class Solution {
    static int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    public int getFood(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        Queue<int[]> q = new ArrayDeque<>();
        var vis = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') {
                    vis[i][j] = true;
                    q.offer(new int[]{0, i, j});
                }
            }
        }

        while (!q.isEmpty()) {
            int t = q.peek()[0];
            int r = q.peek()[1];
            int c = q.peek()[2];
            q.poll();

            if (grid[r][c] == '#')
                return t;
            
            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != 'X') {
                    vis[nr][nc] = true;
                    q.offer(new int[] {t + 1, nr, nc});
                }
            }
        }
        return -1;
    }
}