class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<int> moves(n * n + 1, -1);

        int idx {1};
        bool ltor = true;

        for (int row = n - 1; row >= 0; row--) {
            for (int i = 0; i < n; i++) {
                int col = ltor ? i : n - i - 1;
                moves[idx++] = board[row][col];
            }
            ltor = !ltor;
        }
        queue<int> q;
        vector<bool> vis(n * n + 1, false);
        q.push(1);
        vis[1] = true;
        int steps = 0;

        while (!q.empty()) {
            auto size = q.size();
            while (size--) {
                auto curr = q.front();
                q.pop();
                if (curr == n * n)
                    return steps;

                for (int dice = 1; dice < 7; dice++) {
                    int next = curr + dice;
                    if (next > n * n)
                        continue;
                    int dest = moves[next] == -1 ? next : moves[next];
                    if (!vis[dest]) {
                        vis[dest] = true;
                        q.push(dest);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};