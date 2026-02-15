public class Solution {
    static int[, ] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0 ,-1}};
    public void WallsAndGates(int[][] rooms) {
        int n = rooms.Length;
        int m = rooms[0].Length;
        int INF = Int32.MaxValue;

        var q = new Queue<(int, int, int)>();
        var vis = new bool[n, m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    vis[i, j] = true;
                    q.Enqueue((0, i, j));
                }
            }
        }

        //Main logic starts
        while (q.Count > 0) {
            var (t, r, c) = q.Dequeue();
            rooms[r][c] = Math.Min(rooms[r][c], t);

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i, 0];
                int nc = c + dirs[i, 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr, nc] && rooms[nr][nc] == INF) {
                    vis[nr, nc] = true;
                    q.Enqueue((t + 1, nr, nc));
                }
            }
        }
    }
}