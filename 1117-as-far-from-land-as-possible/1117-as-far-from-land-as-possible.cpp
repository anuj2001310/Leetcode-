class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        queue<pair<int, pair<int, int>>> q;
        int time = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    cnt++;
                    vis[i][j] = true;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            time = fmax(time, t);
            q.pop();
            for (int i = 0; i < dirs.size(); ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                    !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({t + 1, {nr, nc}});
                }
            }
        }
        if (cnt == 0 or cnt == n * m)
            return -1;
        return time;
    }
};