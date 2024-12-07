public class Solution {
    class pair {
        public int first;
        public int second;

        public pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    int bfs (int r, int c, int[][] grid, bool[, ] vis) {
        var q = new Queue<pair>();
        int cnt = 0;
        vis[r, c] = true;
        int n = grid.Length;
        int m = grid[0].Length;
        int[, ] dirs = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};
        q.Enqueue(new pair(r, c));
        while (q.Count() != 0) {
            pair p = q.Dequeue();
            int R = p.first;
            int C = p.second;
            cnt++;
            for (int i = 0; i < 4; ++i) {
                int nR = R + dirs[i, 0];
                int nC = C + dirs[i, 1];
                if (nR >= 0 && nR < n && nC >= 0 && nC < m && grid[nR][nC] == 1 && !vis[nR, nC]) {
                    q.Enqueue(new pair(nR, nC));
                    vis[nR, nC] = true;
                }
            }
        }
        return cnt;
    }
    public int MaxAreaOfIsland(int[][] grid) {
        var maxArea = 0;
        var n = grid.Length;
        var m = grid[0].Length;
        bool[, ] vis = new bool[n, m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i, j]) 
                    maxArea = Math.Max(maxArea, bfs (i, j, grid, vis));
            }
        }
        return maxArea;
    }
}