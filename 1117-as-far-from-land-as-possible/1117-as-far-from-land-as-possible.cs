public class Solution {
    class pair {
        public int time;
        public int first;
        public int second;

        public pair(int time, int first, int second) {
            this.time = time;
            this.first = first;
            this.second = second;
        }
    }

    public int MaxDistance(int[][] grid) {
        int cnt = 0;
        var n = grid.Length;
        var m = grid[0].Length;
        var time = -1;
        bool[, ] vis = new bool[n, m];
        int[, ] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        var q = new Queue<pair>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    cnt++;
                    vis[i, j] = true;
                    q.Enqueue(new pair(0, i, j));
                }
            }
        }

        if (cnt == 0 || cnt == (n * m))
            return -1;

        while (q.Count() != 0) {
            pair p = q.Dequeue();
            var t = p.time;
            var r = p.first;
            var c = p.second;
            time = Math.Max(time, t);
            for (int i = 0; i < 4; ++i) {
                var nr = r + dirs[i, 0];
                var nc = c + dirs[i, 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr, nc]) {
                    vis[nr, nc] = true;
                    q.Enqueue(new pair(t + 1, nr, nc));
                }
            }
        }
        return time;
    }
}