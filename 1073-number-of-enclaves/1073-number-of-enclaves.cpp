class Solution {
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis,
             int n, int m) {
        vis[r][c] = true;
        for (int i = 0; i < dir.size(); ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] and
                !vis[nr][nc]) {
                dfs(nr, nc, grid, vis, n, m);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 or i == n - 1 or j == 0 or j == m - 1) {
                    if (grid[i][j] and !vis[i][j]) {
                        dfs(i, j, grid, vis, n, m);
                    }
                }
            }
        }
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] and !vis[i][j])
                    ++cnt;
            }
        }

        return cnt;
    }
};