class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions:
        // 0 = up, 1 = right, 2 = down, 3 = left
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // For each street type, store allowed directions
        unordered_map<int, vector<int>> roads;
        roads[1] = {1, 3}; // right, left
        roads[2] = {0, 2}; // up, down
        roads[3] = {3, 2}; // left, down
        roads[4] = {1, 2}; // right, down
        roads[5] = {3, 0}; // left, up
        roads[6] = {1, 0}; // right, up

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            int street = grid[r][c];

            for (int dir : roads[street]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (visited[nr][nc])
                    continue;

                int nextStreet = grid[nr][nc];

                // Opposite direction must exist in neighboring street
                int opposite = (dir + 2) % 4;

                bool connected = false;
                for (int nextDir : roads[nextStreet]) {
                    if (nextDir == opposite) {
                        connected = true;
                        break;
                    }
                }

                if (connected) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};