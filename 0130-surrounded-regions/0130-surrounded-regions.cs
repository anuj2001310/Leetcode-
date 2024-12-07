public class Solution {
    class pair {
        public int first;
        public int second;

        public pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    public void Solve(char[][] board) {
        int n = board.Length;
        int m = board[0].Length;
        bool[, ] vis = new bool[n, m];

        var q = new Queue<pair>();
        int[, ] dirs = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        vis[i, j] = true;
                        q.Enqueue(new pair(i, j));
                    }
                }
            }
        }

        while (q.Count() != 0) {
            pair p = q.Dequeue();
            int r = p.first;
            int c = p.second;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i, 0];
                int nc = c + dirs[i, 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && !vis[nr, nc]) {
                    vis[nr, nc] = true;
                    q.Enqueue(new pair(nr, nc));
                }
            }
        }

        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (board[i][j] == 'O' &&!vis[i, j])
                    board[i][j] = 'X';
            }
        }
    }
}