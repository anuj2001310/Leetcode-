class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();    // Rows
        int m = grid[0].size(); // Cols
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c]) {
                    int left = c - 1, right = c + 1;
                    int up = r - 1, down = r + 1;

                    // left - movement
                    while (left >= 0) {
                        if (grid[r][left] and !vis[r][left]) {
                            vis[r][left] = true;
                            cnt++;
                        }
                        left--;
                    }
                    // right - movement
                    while (right < m) {
                        if (grid[r][right] and !vis[r][right]) {
                            vis[r][right] = true;
                            cnt++;
                        }
                        right++;
                    }
                    // up - movement
                    while (up >= 0) {
                        if (grid[up][c] and !vis[up][c]) {
                            vis[up][c] = true;
                            cnt++;
                        }
                        up--;
                    }
                    // down - movement
                    while (down < n) {
                        if (grid[down][c] and !vis[down][c]) {
                            vis[down][c] = true;
                            cnt++;
                        }
                        down++;
                    }
                }
            }
        }
        return cnt;
    }
};