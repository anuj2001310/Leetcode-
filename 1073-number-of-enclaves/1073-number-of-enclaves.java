class Solution {
    class pair {
        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static int[][] dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][] vis = new boolean[n][m];
        Queue<pair> q = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        vis[i][j] = true;
                        q.add(new pair(i, j));
                    }
                }
            }
        }
        while (!q.isEmpty()) {
            int r = q.peek().first;
            int c = q.peek().second;
            q.poll();
            for (int i = 0; i < dir.length; ++i) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]) {
                    q.add(new pair(nr, nc));
                    vis[nr][nc] = true;
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