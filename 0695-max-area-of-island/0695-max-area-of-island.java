class Solution {
    static class pair {
        int first;
        int second;
        pair (int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    static int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int bfs (int r, int c, int[][] grid, boolean[][] vis) {
        Queue<pair> q = new LinkedList<>();
        int cnt = 0;
        vis[r][c] = true;
        int n = grid.length;
        int m = grid[0].length;
        q.add(new pair(r, c));
        while (!q.isEmpty()) {
            int R = q.peek().first;
            int C = q.peek().second;
            q.poll();
            cnt++;
            for (int i = 0; i < dirs.length; ++i) {
                int nR = R + dirs[i][0];
                int nC = C + dirs[i][1];
                if (nR >= 0 && nR < n && nC >= 0 && nC < m && grid[nR][nC] == 1 && !vis[nR][nC]) {
                    q.add(new pair(nR, nC));
                    vis[nR][nC] = true;
                }
            }
        }
        return cnt;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) 
                    maxArea = Math.max(maxArea, bfs (i, j, grid, vis));
            }
        }
        return maxArea;
    }
}