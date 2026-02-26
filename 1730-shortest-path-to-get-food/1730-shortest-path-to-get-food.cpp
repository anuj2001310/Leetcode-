using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;

using pii = pair<int, int>;
#define Rep(a, b, c, d) for (int a = b; a < c; a += d)


class Solution {
private:
vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pii>> q;
        vvb vis(n, vb(m, false));
        
        Rep(i, 0, n, 1) {
            Rep(j, 0, m, 1) {
                if (grid[i][j] == '*') {
                    vis[i][j] = true;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            auto t = q.front().first;
            auto r = q.front().second.first;
            auto c = q.front().second.second;
            q.pop();

            if (grid[r][c] == '#')
                return t;
            
            Rep(x, 0, 4, 1) {
                auto nr = r + dirs[x][0];
                auto nc = c + dirs[x][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != 'X') {
                    vis[nr][nc] = true;
                    q.push({t + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};