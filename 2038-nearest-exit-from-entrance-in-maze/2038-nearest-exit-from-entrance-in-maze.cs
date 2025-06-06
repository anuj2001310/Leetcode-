public class Solution {
    public int NearestExit(char[][] maze, int[] entrance) {
        var n = maze.Length;
        var m = maze[0].Length;

        int[, ] dirs = {{-1, 0 }, {0, 1 }, {1, 0 }, {0, -1}};
        var q = new Queue<int[]>();
        bool[, ] vis = new bool[n, m];

        int u = entrance[0], v = entrance[1];
        vis[u, v] = true;
        q.Enqueue(new int[] {0, u, v});

        while (q.Count() != 0) {
            int dis = q.Peek()[0];
            int r = q.Peek()[1];
            int c = q.Peek()[2];
            q.Dequeue();

            if ((r == 0 || r == n - 1 || c == 0 || c == m - 1) && (r != u || c != v))
                return dis;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i, 0];
                int nc = c + dirs[i, 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr, nc] && maze[nr][nc] == '.') {
                    q.Enqueue(new int[] {dis + 1, nr, nc});
                    vis[nr, nc] = true;
                }
            }
        }
        return -1;
    }
}