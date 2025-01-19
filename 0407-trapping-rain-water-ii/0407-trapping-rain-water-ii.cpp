typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        vvb vis(n, vb(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    pq.push({mat[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }

        vector<pii> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        int ans = 0;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int val = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            for (auto& dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 and ny >= 0 and nx < n and ny < m and !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    ans += fmax(0, val - mat[nx][ny]);
                    pq.push({fmax(val, mat[nx][ny]), {nx, ny}});
                } 
            }
        }
        return ans;
    }
};