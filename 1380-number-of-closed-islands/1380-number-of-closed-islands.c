static int dirs[][4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int r, int c, int** grid, bool** vis, int n, int m) {
    vis[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dirs[i][0];
        int nc = c + dirs[i][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !grid[nr][nc] &&
            !vis[nr][nc])
            dfs(nr, nc, grid, vis, n, m);
    }
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = (*gridColSize);

    bool** vis = (bool**)calloc(sizeof(bool*), n);
    
    for (int i = 0; i < n; ++i) 
        vis[i] = (bool*)calloc(sizeof(bool), m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (!grid[i][j] && !vis[i][j])
                    dfs(i, j, grid, vis, n, m);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!grid[i][j] && !vis[i][j]) {
                cnt++;
                dfs(i, j, grid, vis, n, m);
            }
        }
    }
    return cnt;
}