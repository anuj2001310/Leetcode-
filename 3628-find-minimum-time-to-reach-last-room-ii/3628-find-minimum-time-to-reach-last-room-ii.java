class Solution {
    public class State {
        int r;
        int c;
        int dis;

        State(int r, int c, int dis) {
            this.r = r;
            this.c = c;
            this.dis = dis;
        }
    }

    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public final int inf = 0x3f3f3f3f;

    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length, m = moveTime[0].length;

        var dist = new int[n][m];
        for (int i = 0; i < n; ++i)
            Arrays.fill(dist[i], inf);

        var vis = new boolean[n][m];

        dist[0][0] = 0;
        PriorityQueue<State> pq = new PriorityQueue<>((a, b) -> a.dis - b.dis);
        pq.offer(new State(0, 0, 0));

        while (!pq.isEmpty()) {
            int r = pq.peek().r;
            int c = pq.peek().c;
            //int dis = pq.peek().dis;
            pq.poll();

            if (r == n - 1 && c == m - 1)
                break;

            for (int i = 0; i < dirs.length; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {

                    int d = Math.max(dist[r][c], moveTime[nr][nc]) + (r + c) % 2 + 1;
                    if (dist[nr][nc] > d) {
                        dist[nr][nc] = d;
                        pq.offer(new State(nr, nc, d));
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
}