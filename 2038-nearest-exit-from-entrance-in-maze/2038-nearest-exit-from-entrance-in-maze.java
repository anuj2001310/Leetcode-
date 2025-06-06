class Solution {
    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public int nearestExit(char[][] maze, int[] entrance) {
        int n = maze.length;
        int m = maze[0].length;

        boolean[][] vis = new boolean[n][m];
        Queue<int[]> q = new ArrayDeque<>();

        int u = entrance[0], v = entrance[1];
        vis[u][v] = true;
        q.offer(new int[] {0, u, v });

        while (!q.isEmpty()) {
            int d = q.peek()[0];
            int r = q.peek()[1];
            int c = q.peek()[2];
            q.poll();

        
            //System.out.println("( " + r + " " + c + " )");
            if ((r == 0 || r == n - 1 || c == 0 || c == m - 1) && (r != entrance[0] || c != entrance[1]))
                return d;

            for (int i = 0; i < dirs.length; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && maze[nr][nc] == '.') {
                    vis[nr][nc] = true;
                    q.offer(new int[] {d + 1, nr, nc });
                }
            }
        }
        return -1;
    }
}