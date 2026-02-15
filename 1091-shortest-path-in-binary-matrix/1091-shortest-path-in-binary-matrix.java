class Solution {
    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, -1 }, { 1, -1 }, { -1, 1 }, { 1, 1 } };

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        if (grid[0][0] == 1)
            return -1;

        Queue<int[]> q = new ArrayDeque<>();
        var vis = new boolean[n][m];

        q.offer(new int[] { 0, 0, 0 });
        vis[0][0] = true;

        while (!q.isEmpty()) {
            int t = q.peek()[0];
            int r = q.peek()[1];
            int c = q.peek()[2];
            q.poll();

            if (r == n - 1 && c == m - 1)
                return t + 1;

            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 0) {
                    q.offer(new int[] { t + 1, nr, nc });
                    vis[nr][nc] = true;
                }
            }
        }

        return -1;
    }
}