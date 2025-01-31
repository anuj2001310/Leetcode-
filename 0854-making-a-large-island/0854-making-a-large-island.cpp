class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows;
        int max_island = 0;
        int w = 0, l = 1, vis = 2;
        auto get_size = [&](int row, int col) -> int {
            grid[row][col] = vis;
            stack<pair<int, int>> st;
            st.push({row, col});
            int is_size = 0;
            set<pair<int, int>> sh;
            while (!st.empty()) {
                auto cur = st.top();
                st.pop();
                int r = cur.first;
                int c = cur.second;
                is_size++;
                for (int i = 0; i < dirs.size(); i++) {
                    int nr = r + dirs[i][0];
                    int nc = c + dirs[i][1];
                    if (nr >= 0 and nr < rows and nc >= 0 and nc < cols) {
                        int ngh = grid[nr][nc];
                        if (ngh == l) {
                            st.push({nr, nc});
                            grid[nr][nc] = vis;
                        } else if (ngh <= w)
                            sh.insert({nr, nc});
                    }
                }
            }
            for (auto& [sr, sc] : sh)
                grid[sr][sc] -= is_size;
            return is_size;
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != l)
                    continue;
                max_island = fmax(max_island, get_size(r, c));
                if (max_island == rows * cols)
                    return max_island;
            }
        }
        if (max_island == 0)
            return 1;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] < w) {
                    int val = grid[r][c];
                    max_island = fmax(max_island, -val + 1);
                    if (max_island == rows * cols)
                        return max_island;
                }
            }
        }
        return max_island;
    }
};