class Solution {
    public int trapRainWater(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        boolean[][] vis = new boolean[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.offer(new int[] { mat[i][j], i, j });
                    vis[i][j] = true;
                }
            }
        }
        int[][] dirs = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
        int ans = 0;
        while (!pq.isEmpty()) {
            int val = pq.peek()[0];
            int x = pq.peek()[1];
            int y = pq.peek()[2];
            pq.poll();
            for (int[] dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    ans += Math.max(0, val - mat[nx][ny]);
                    pq.offer(new int[] { Math.max(val, mat[nx][ny]), nx, ny });
                }
            }
        }
        return ans;
    }
}