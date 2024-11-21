class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (auto& arr : walls)
            vis[arr[0]][arr[1]] = 3;

        for (auto& arr : guards)
            vis[arr[0]][arr[1]] = 2;

        for (int i = 0; i < guards.size(); ++i) {
            int r = guards[i][0];
            int c = guards[i][1];

            int left = c - 1, right = c + 1;
            int up = r - 1, down = r + 1;

            // left - movement
            while (left >= 0) {
                if (vis[r][left] == 3 or vis[r][left] == 2)
                    break;
                vis[r][left] = 1;
                left--;
            }

            // right - movement
            while (right < n) {
                if (vis[r][right] == 3 or vis[r][right] == 2)
                    break;
                vis[r][right] = 1;
                right++;
            }

            // up - movement
            while (up >= 0) {
                if (vis[up][c] == 3 or vis[up][c] == 2)
                    break;
                vis[up][c] = 1;
                up--;
            }

            // down - movement
            while (down < m) {
                if (vis[down][c] == 3 or vis[down][c] == 2)
                    break;
                vis[down][c] = 1;
                down++;
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; ++j)
                if (vis[i][j] == 0)
                    cnt++;

        return cnt;
    }
};