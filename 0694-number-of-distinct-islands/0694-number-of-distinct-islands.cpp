using pii = pair<int, int>;
using vi = vector<int>;
typedef vector<vi> vvi;

using vb = vector<bool>;
typedef vector<vb> vvb;

#define Rep(a, b, c, d) for (int a = b; a < c; a += d)
#define pb push_back
class Solution {
    vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis,
             int n, int m, int s, int e, vector<pair<int, int>>& vec) {

        vis[r][c] = true;
        vec.pb({r - s, c - e});
        for (auto& dir : dirs) {
            auto nr = r + dir[0];
            auto nc = c + dir[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                grid[nr][nc])
                dfs(nr, nc, grid, vis, n, m, s, e, vec);
        }
    }

public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = size(grid), m = size(grid[0]);
        vvb vis(n, vb(m, false));
        set<vector<pii>> st;

        Rep(i, 0, n, 1) {
            Rep(j, 0, m, 1 ) {
                vector<pii> vec;
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, grid, vis, n, m, i, j, vec);
                    st.insert(vec);
                }
            }
        }

        return size(st);
    }
};