typedef pair<int, int> pii;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

#define Rep(a, b, c, d) for (int a = b; a < c; a += d)

class Solution {
    vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(int r, int c, vvc& grid, vvb& vis, int n, int m) {
        if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] ||
            grid[r][c] == '0')
            return;

        vis[r][c] = true;
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            dfs(nr, nc, grid, vis, n, m);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = size(grid);
        int m = size(grid[0]);
        vvb vis(n, vb(m, false));
        int cnt = 0;

        Rep(i, 0, n, 1) {
            Rep(j, 0, m, 1) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis, n, m);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};