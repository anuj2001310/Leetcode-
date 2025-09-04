class Solution {
    static int[][] dirs = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

    public int shortestPathBinaryMatrix(int[][] grid) {
        int sr = 0, sc = 0;
        if (grid[0][0] != 0)
            return -1;

        int n = grid.length;
        int m = grid[0].length;
        Queue<int[]> q = new ArrayDeque<>();

        var vis = new boolean[n][m];

        int dr = n - 1, dc = m - 1;

        vis[sr][sc] = true;
        q.offer(new int[] { sr, sc, 0 });

        int time = 0;
        while (!q.isEmpty()) {
            int r = q.peek()[0];
            int c = q.peek()[1];
            int t = q.peek()[2];
            q.poll();

            time = Math.max(time, t);

            if (r == dr && c == dc)
                return time + 1;
            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 0) {
                    vis[nr][nc] = true;
                    q.offer(new int[] { nr, nc, t + 1 });
                }
            }
        }
        return -1;
    }
}