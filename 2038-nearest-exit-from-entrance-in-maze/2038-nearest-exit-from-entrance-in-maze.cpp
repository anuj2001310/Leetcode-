class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int ans = -1;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, pair<int, int>>> q;

        int r = entrance[0], c = entrance[1];
        vis[r][c] = true;
        q.push({0, {r, c}});

        while (!q.empty()) {
            auto d = q.front().first;
            auto r = q.front().second.first;
            auto c = q.front().second.second;
            q.pop();
            vector<int> temp = {r, c};
            if ((r == 0 or c == 0 or r == n - 1 or c == m - 1) and (temp != entrance))
                return d;
            for (int i = 0; i < dirs.size(); i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 and nc >= 0 and nr < n and nc < m and
                    !vis[nr][nc] and maze[nr][nc] == '.') {
                    q.push({d + 1, {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
        }
        return -1;
    }
};