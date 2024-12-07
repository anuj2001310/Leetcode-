class Solution {
    static class pair {
        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    int bfs(int row, int col, int[][] grid, boolean[][] vis) {
        int n = grid.length;
        int m = grid[0].length;
        vis[row][col] = true;
        Queue<pair> q = new LinkedList<>();
        int fish = 0;
        q.add(new pair(row, col));
        while (!q.isEmpty()) {
            int r = q.peek().first;
            int c = q.peek().second;
            q.poll();
            fish += grid[r][c];
            for (int i = 0; i < dirs.length; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] > 0) {
                    vis[nr][nc] = true;
                    q.add(new pair(nr, nc));
                }
            }
        }
        return fish;
    }

    public int findMaxFish(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int maxFish = 0;
        boolean[][] vis = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0 && !vis[i][j])
                    maxFish = Math.max(maxFish, bfs(i, j, grid, vis));
            }
        }
        return maxFish;
    }
}