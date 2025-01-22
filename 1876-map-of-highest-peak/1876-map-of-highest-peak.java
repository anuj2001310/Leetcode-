class Solution {
    class pair {
        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public int[][] highestPeak(int[][] isWater) {
        int n = isWater.length;
        int m = isWater[0].length;
        int[][] height = new int[n][m];
        for (int i = 0; i < n; ++i)
            Arrays.fill(height[i], -1);

        Queue<pair> q = new LinkedList<>();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.offer(new pair(i, j));
                    height[i][j] = 0;
                }
            }
        }
        
        while (!q.isEmpty()) {
            int r = q.peek().first;
            int c = q.peek().second;
            q.poll();
            for (int i = 0; i < dirs.length; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && height[nr][nc] == -1) {
                    height[nr][nc] = height[r][c] + 1;
                    q.offer(new pair(nr, nc));
                }
            }
        }
        return height;
    }
}