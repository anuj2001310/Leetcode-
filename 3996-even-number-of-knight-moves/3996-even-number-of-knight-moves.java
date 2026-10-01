class Solution {
    static int[][] dirs = { { -1, -2 },
            { -2, -1 },
            { -1, 2 },
            { -2, 1 },
            { 1, -2 },
            { 2, -1 },
            { 1, 2 },
            { 2, 1 } };

    public boolean canReach(int[] start, int[] target) {
        boolean[][] vis = new boolean[8][8];
        Queue<int[]> q = new ArrayDeque<>();
        int u = start[0], v = start[1];
        int sr = target[0], sc = target[1];
        q.offer(new int[] { u, v });
        vis[u][v] = true;

        int ans = 0;
        while (!q.isEmpty()) {
            int n = q.size();
            while (n-- > 0) {

                int r = q.peek()[0];
                int c = q.peek()[1];
                q.poll();

                if ((sr == r && sc == c) && ((ans & 1) == 0))
                    return true;

                for (int i = 0; i < 8; ++i) {
                    int nr = r + dirs[i][0];
                    int nc = c + dirs[i][1];

                    if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && !vis[nr][nc]) {
                        q.offer(new int[] { nr, nc });
                        vis[nr][nc] = true;
                    }
                }
            }
            ans++;
        }
        return false;
    }
}