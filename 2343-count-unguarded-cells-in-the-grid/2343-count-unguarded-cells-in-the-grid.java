class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] vis = new int[m][n];
        for (int[] arr : guards)
            vis[arr[0]][arr[1]] = 2;
        for (int[] arr : walls)
            vis[arr[0]][arr[1]] = 3;

        for (int i = 0; i < guards.length; ++i) {
            int r = guards[i][0];
            int c = guards[i][1];

            int left = c - 1, right = c + 1;
            int up = r - 1, down = r + 1;

            // left - movement
            while (left >= 0) {
                if (vis[r][left] == 3 || vis[r][left] == 2)
                    break;
                vis[r][left] = 1;
                left--;
            }

            // right - movement
            while (right < n) {
                if (vis[r][right] == 3 || vis[r][right] == 2)
                    break;
                vis[r][right] = 1;
                right++;
            }

            // up - movement
            while (up >= 0) {
                if (vis[up][c] == 3 || vis[up][c] == 2)
                    break;
                vis[up][c] = 1;
                up--;
            }

            // down - movement
            while (down < m) {
                if (vis[down][c] == 3 || vis[down][c] == 2)
                    break;
                vis[down][c] = 1;
                down++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                if (vis[i][j] == 0)
                    cnt += 1;
        }
        return cnt;
    }
}