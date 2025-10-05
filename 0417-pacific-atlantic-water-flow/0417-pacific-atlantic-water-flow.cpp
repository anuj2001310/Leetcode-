class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        auto dfs = [&](this auto&& dfs, int i, int j,
                       vector<vector<bool>>& visit) -> void {
            visit[i][j] = true;
            for (auto& d : dir) {
                int nxt_i = i + d[0];
                int nxt_j = j + d[1];
                if (nxt_i < 0 || nxt_j < 0 || nxt_i >= m || nxt_j >= n ||
                    visit[nxt_i][nxt_j] ||
                    heights[i][j] > heights[nxt_i][nxt_j]) {
                    continue;
                }
                visit[nxt_i][nxt_j] = true;
                dfs(nxt_i, nxt_j, visit);
            }
        };

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pac);
            dfs(i, n - 1, atl);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, pac);
            dfs(m - 1, j, atl);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};