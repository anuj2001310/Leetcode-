class Solution {
    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    final int INF = Integer.MAX_VALUE;

    public void wallsAndGates(int[][] rooms) {
        int n = rooms.length;
        int m = rooms[0].length;
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] vis = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    vis[i][j] = true;
                    q.offer(new int[] { 0, i, j });
                }
            }
        }

        while (!q.isEmpty()) {
            int t = q.peek()[0];
            int r = q.peek()[1];
            int c = q.peek()[2];
            q.poll();

            rooms[r][c] = Math.min(rooms[r][c], t);
            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && rooms[nr][nc] == INF) {
                    q.offer(new int[] { t + 1, nr, nc });
                    vis[nr][nc] = true;
                }
            }
        }
    }
}