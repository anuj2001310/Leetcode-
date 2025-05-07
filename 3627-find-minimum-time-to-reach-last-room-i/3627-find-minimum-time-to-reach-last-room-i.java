class Solution {
    static int[][] dirs = {{-1, 0 }, {0, 1 }, {1, 0 }, {0, -1 }};

    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length;
        int m = moveTime[0].length;

        boolean[][] vis = new boolean[n][m];

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        int curr_time = 0;
        pq.offer(new int[] {0, 0, 0});

        while (!pq.isEmpty()) {
            curr_time = pq.peek()[0];
            int r = pq.peek()[1];
            int c = pq.peek()[2];
            pq.poll();

            if (r == n - 1 && c == m - 1)
                return curr_time;

            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    if (curr_time >= moveTime[nr][nc])
                        pq.offer(new int[] {curr_time + 1, nr, nc});
                    else
                        pq.offer(new int[] {moveTime[nr][nc] + 1, nr, nc});
                }
            }
        }
        return -1;
    }
}