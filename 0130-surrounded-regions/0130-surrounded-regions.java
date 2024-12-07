class Solution {
    static class pair {
        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;

        boolean[][] vis = new boolean[n][m];
        Queue<pair> q = new LinkedList<>();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        vis[i][j] = true;
                        q.add(new pair(i, j));
                    }
                }
            }
        }

        while (!q.isEmpty()) {
            int r = q.peek().first;
            int c = q.peek().second;
            q.poll();
            for (int i = 0; i < dirs.length; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        !vis[nr][nc] && board[nr][nc] == 'O') {
                    vis[nr][nc] = true;
                    q.add(new pair(nr, nc));
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
        }
    }
}