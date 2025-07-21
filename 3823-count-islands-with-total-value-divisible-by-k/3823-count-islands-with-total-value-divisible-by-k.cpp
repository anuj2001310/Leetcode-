class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    long long dfs (int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis, int n, int m) {
        vis[r][c] = true;
        long long sum = grid[r][c];
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and grid[nr][nc])
                sum += dfs (nr, nc, grid, vis, n, m);
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int curr = 0;
        vector<vector<bool>> vis (n, vector<bool>(m, false));
        
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (!vis[i][j] and grid[i][j]) {
                    auto val = dfs (i, j, grid, vis, n, m);
                    if (val % k == 0)
                        curr++;
                }
            }
        }
        return curr;
    }
};