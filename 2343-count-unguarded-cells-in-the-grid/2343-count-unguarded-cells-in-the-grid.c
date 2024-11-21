int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    int vis[m][n] = {};
    
    for (int i = 0; i < guardsSize; ++i) {
        int r = guards[i][0];
        int c = guards[i][1];
        vis[r][c] = 2;
    }

    for (int i = 0; i < wallsSize; ++i) {
        int r = walls[i][0];
        int c = walls[i][1];
        vis[r][c] = 3;
    }
    for (int u = 0; u < guardsSize; ++u) {
        int r = guards[u][0];
        int c = guards[u][1];

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
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; ++j)
            if (vis[i][j] == 0)
                cnt++;

    return cnt;
}