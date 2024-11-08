public class Solution {
    public class Pair {
        public int first;
        public int second;
        public Pair(int f, int s) {
            first = f;
            second = s;
        }
    }
    public int[][] FloodFill(int[][] image, int sr, int sc, int color) {
        int n = image.Length;
        int m = image[0].Length;
        int initial = image[sr][sc];

        int[][] ans = image;

        var q = new Queue<Pair>();
        ans[sr][sc] = color;
        q.Enqueue(new Pair(sr, sc));

        int[, ] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
        while (q.Count() != 0) {
            int r = q.Peek().first;
            int c = q.Peek().second;
            q.Dequeue();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i, 0];
                int nc = c + dirs[i, 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == initial && ans[nr][nc] != color) {
                    q.Enqueue(new Pair(nr, nc));
                    ans[nr][nc] = color;
                }
            }
        }

        return ans;
    }
}