class Solution {
    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    static class pair {
        int time;
        int first;
        int second;

        pair(int time, int first, int second) {
            this.time = time;
            this.first = first;
            this.second = second;
        }
    }

    public int maxDistance(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int cnt = 0;
        int tim = -1;
        Queue<pair> q = new LinkedList<>();
        boolean[][] vis = new boolean[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    cnt++;
                    vis[i][j] = true;
                    q.offer(new pair(0, i, j));
                }
            }
        }
        if (cnt == 0 || cnt == n * m)
            return -1;
        while (!q.isEmpty()) {
            int t = q.peek().time;
            int r = q.peek().first;
            int c = q.peek().second;
            tim = Math.max(tim, t);
            q.poll();
            for (int i = 0; i < dirs.length; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.offer(new pair(t + 1, nr, nc));
                }
            }
        }
        return tim;
    }
}