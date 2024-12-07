class Solution {
private:
    //                          up,      right,   down,    left
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int bfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid, int n, int m) {
        int cnt = 0;
        queue<pair<int, int>> q;
        vis[r][c] = true;
        q.push({r, c});
        while (!q.empty()) {
            int R = q.front().first;
            int C = q.front().second;
            q.pop();
            cnt++;
            for (int i = 0; i < dirs.size(); ++i) {
                int nr = R + dirs[i][0];
                int nc = C + dirs[i][1];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                    grid[nr][nc] and !vis[nr][nc]) {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
        return cnt;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] and !vis[i][j]) {
                    maxArea = fmax(maxArea, bfs(i, j, vis, grid, n, m));
                }
            }
        }
        return maxArea;
    }
};