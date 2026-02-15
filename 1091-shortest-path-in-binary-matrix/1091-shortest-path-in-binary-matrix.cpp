using pii = pair<int, int>;
using vi = vector<int>;
typedef vector<vi> vvi;

using vb = vector<bool>;
using vvb = vector<vb>;

class Solution {
private:
    vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = size(grid);
        int m = size(grid[0]);
        if (grid[0][0] == 1)
            return -1;
        
        queue<pair<int, pii>> q;
        vvb vis(n, vb(m, false));

        q.push({0, {0, 0}});
        vis[0][0] = true;

        while (!q.empty()) {
            auto t = q.front().first;
            auto r = q.front().second.first;
            auto c = q.front().second.second;

            q.pop();

            if (r == n - 1 && c == m - 1)
                return t + 1;
            
            for (auto& dir : dirs) {
                auto nr = r + dir[0];
                auto nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 0) {
                    q.push({t + 1, {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
        }

        return -1;
    }
};