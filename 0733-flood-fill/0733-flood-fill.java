class Solution {
    void dfs(int r, int c, int[][] image, int[][] ans, int n, int m, int initial, int color) {
        ans[r][c] = color;
        for (int i = 0; i < dirs.length; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == initial && ans[nr][nc] != color) {
                dfs(nr, nc, image, ans, n, m, initial, color);
            }
        }
    }

    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int n = image.length;
        int m = image[0].length;
        int initial = image[sr][sc];

        int[][] ans = image;
        dfs(sr, sc, image, ans, n, m, initial, color);

        return ans;
    }
}