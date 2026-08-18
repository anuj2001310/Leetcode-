typedef pair<int, int> pii;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
#define rep(a, b, c, d) for (int a = b; a < c; a += d)

class Solution {
    vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(int r, int c, vvb& vis, vvi& land, int& lr, int& lc, int n,
             int m) {
        if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || land[r][c] == 0)
            return;

        lr = fmax(lr, r);
        lc = fmax(lc, c);

        vis[r][c] = true;
        rep(k, 0, 4, 1) {
            auto nr = r + dirs[k][0];
            auto nc = c + dirs[k][1];
            dfs(nr, nc, vis, land, lr, lc, n, m);
        }

        return;
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = size(land);
        int m = size(land[0]);

        vvb vis(n, vb(m, false));
        vvi ans;
        rep(r, 0, n, 1) {
            rep(c, 0, m, 1) {
                if (!vis[r][c] && land[r][c] == 1) {
                    int lr = r, lc = c;
                    dfs(r, c, vis, land, lr, lc, n, m);
                    vi temp = {r, c, lr, lc};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};