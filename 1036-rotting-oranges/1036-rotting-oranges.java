class Solution {
    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    static class Pair {
        int val;
        int first;
        int second;

        Pair(int val, int first, int second) {
            this.val = val;
            this.first = first;
            this.second = second;
        }
    }

    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] vis = new int[n][m];

        int cnt = 0;
        Queue<Pair> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.offer(new Pair(0, i, j));
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1)
                    cnt++;
            }
        }

        int tm = 0;
        int cf = 0;
        while (!q.isEmpty()) {
            int val = q.peek().val;
            int r = q.peek().first;
            int c = q.peek().second;
            q.poll();
            tm = Math.max(tm, val);
            for (int i = 0; i < dirs.length; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                    q.offer(new Pair(val + 1, nr, nc));
                    vis[nr][nc] = 2;
                    cf++;
                }
            }
        }
        if (cf != cnt)
            return -1;
        return tm;
    }
}