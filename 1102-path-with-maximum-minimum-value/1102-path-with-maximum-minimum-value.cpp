#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
using vb = vector<bool>;
using vvb = vector<vb>;

class Solution {
private:
    vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<vector<int>> pq;
        pq.push({grid[0][0], 0, 0});

        vvb vis(n, vb(m, false));
        vis[0][0] = true;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int val = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == n - 1 && c == m - 1)
                return val;

            for (auto& d : dirs) {
                auto nr = r + d[0];
                auto nc = c + d[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    pq.push({min(val, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};