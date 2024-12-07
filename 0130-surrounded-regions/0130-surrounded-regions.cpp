class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    if (board[i][j] == 'O') {
                        vis[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < dirs.size(); ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and
                    !vis[nr][nc] and board[nr][nc] == 'O') {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                if (board[i][j] == 'O' and !vis[i][j])
                    board[i][j] = 'X';
        }
    }
};