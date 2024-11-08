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

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int n = image.length;
        int m = image[0].length;
        int initial = image[sr][sc];

        int[][] ans = image;
        Queue<pair> q = new LinkedList<>();
        q.add(new pair(sr, sc));
        ans[sr][sc] = color;

        while (!q.isEmpty()) {
            int r = q.peek().first;
            int c = q.peek().second;
            q.poll();
            for (int i = 0; i < dirs.length; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == initial && ans[nr][nc] != color) {
                    ans[nr][nc] = color;
                    q.add(new pair(nr, nc));
                }
            }
        }

        return ans;
    }
}