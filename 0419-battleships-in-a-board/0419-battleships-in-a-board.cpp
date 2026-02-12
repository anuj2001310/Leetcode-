#include <bits/stdc++.h>
using namespace std;

#define Rep(i, n) for (int i = 0; i < n; i++)
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

class Solution {
private:
    vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(int r, int c, vvc& board, vvb& vis, int n, int m) {
        vis[r][c] = true;
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                board[nr][nc] == 'X')
                dfs(nr, nc, board, vis, n, m);
        }
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int n = size(board);
        int m = size(board[0]);
        int cnt = 0;
        vvb vis(n, vb(m, false));
        Rep(i, n) {
            Rep(j, m) {
                if (board[i][j] == 'X' && !vis[i][j]) {
                    dfs(i, j, board, vis, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};