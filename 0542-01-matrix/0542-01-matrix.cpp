class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            int val = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            dist[r][c] = val;
            for (int i = 0; i < dirs.size(); ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({val + 1, {nr, nc}});
                }
            }
        }
        return dist;
    }
};