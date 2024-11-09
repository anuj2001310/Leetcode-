public class Solution {
    public class Pair {
        public int first;
        public int second;
        public Pair(int f, int s) {
            first = f;
            second = s;
        }
    }

    public int NumEnclaves(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        bool[, ] vis = new bool[n, m];

        int[, ] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        var q = new Queue<Pair>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        q.Enqueue(new Pair(i, j));
                        vis[i, j] = true;
                    }
                }
            }
        }
        while (q.Count() != 0) {
            int r = q.Peek().first;
            int c = q.Peek().second;
            q.Dequeue();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i, 0];
                int nc = c + dirs[i, 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr, nc]) {
                    q.Enqueue(new Pair(nr, nc));
                    vis[nr, nc] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i, j])
                    ++cnt;
            }
        }
        return cnt;
    }
}