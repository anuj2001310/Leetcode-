#define P pair<int, pair<int, int>>
class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cost = 0;
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        res[0][0] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for (int i = 0; i < dirs.size(); ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 and nr < m and nc >= 0 and nc < n) {
                    int w = (grid[nr][nc]) ? 1 : 0;
                    if (d + w < res[nr][nc]) {
                        res[nr][nc] = d + w;
                        pq.push({d + w, {nr, nc}});
                    }
                }
            }
        }
        return res[m - 1][n - 1];
    }
};