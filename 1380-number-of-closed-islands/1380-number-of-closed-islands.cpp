class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis,
             int n, int m) {
        vis[r][c] = true;
        for (int i = 0; i < dirs.size(); ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                grid[nr][nc] == 0 and !vis[nr][nc])
                dfs(nr, nc, grid, vis, n, m);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 or i == n - 1 or j == 0 or j == m - 1)
                    if (grid[i][j] == 0 and !vis[i][j])
                        dfs(i, j, grid, vis, n, m);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0 and !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }
        return cnt;
    }
};