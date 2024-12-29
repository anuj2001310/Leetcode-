class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        queue<pair<int, pair<int, int>>> q;
        // [ {_ , {_ , _}} ] Queue structure
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 2) {
                    q.push({0, {i, j}});
                    vis[i][j] = 2;
                }
                if (mat[i][j] == 1)
                    cnt++;
            }
        }
        int tm = 0;
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int cf = 0;
        while (!q.empty()) {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int d = q.front().first;
            q.pop();
            tm = fmax(tm, d);
            for (int i = 0; i < dir.size(); ++i) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                    vis[nr][nc] == 0 and mat[nr][nc] == 1) {
                    q.push({d + 1, {nr, nc}});
                    vis[nr][nc] = 2;
                    cf++;
                }
            }
        }
        if (cf != cnt)
            return -1;
        return tm;
    }
};