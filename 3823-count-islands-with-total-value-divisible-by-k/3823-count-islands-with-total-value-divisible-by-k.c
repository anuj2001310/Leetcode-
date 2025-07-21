int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int n = gridSize, m = (*gridColSize);
    int cnt = 0;
    bool** vis = (bool**)malloc(sizeof(bool*) * n);
    
    for (int i = 0; i < n; i++)
        vis[i] = (bool*)calloc(m, sizeof(bool));

    long long dfs (int r, int c) {
        if (r >= n || r < 0 || c >= m || c < 0 || vis[r][c] || grid[r][c] == 0)
            return 0;

        vis[r][c] = true;
        long long sum = grid[r][c];
        sum += dfs (r - 1, c);
        sum += dfs (r, c + 1);
        sum += dfs (r + 1, c);
        sum += dfs (r, c - 1);
            
        return sum;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j]) {
                long long val = dfs (i, j);
                if (val % k == 0)
                    cnt++;
            }
        }
    }
    return cnt;
}