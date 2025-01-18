class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        dq.push_back({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto[x, y] = dq.front();
            dq.pop_front();
            for (int i = 0; i < dirs.size(); i++) {
                int nx = x + dirs[i].first;
                int ny = y + dirs[i].second;
                if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
                    int cost = (grid[x][y] == i + 1) ? 0 : 1;
                    if (dist[nx][ny] > dist[x][y] + cost) {
                        dist[nx][ny] = dist[x][y] + cost;
                        if (cost == 0)
                            dq.push_front({nx, ny});
                        else
                            dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};