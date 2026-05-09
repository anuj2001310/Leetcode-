class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = min(m, n) / 2;
        int l;
        int i;
        int j;
        for (l = 0; l < count; l++) {
            vector<int> chain;

            i = l;
            for (j = l; j < n - l - 1; j++) {
                chain.push_back(grid[i][j]);
            }
            j = n - l - 1;
            for (i = l; i < m - l - 1; i++) {
                chain.push_back(grid[i][j]);
            }
            i = m - l - 1;
            for (j = n - l - 1; j > l; j--) {
                chain.push_back(grid[i][j]);
            }
            j = l;
            for (i = m - l - 1; i > l; i--) {
                chain.push_back(grid[i][j]);
            }

            int index = k % chain.size();

            i = l;
            for (j = l; j < n - l - 1; j++) {
                grid[i][j] = chain[index];
                index = (index + 1) % chain.size();
            }
            j = n - l - 1;
            for (i = l; i < m - l - 1; i++) {
                grid[i][j] = chain[index];
                index = (index + 1) % chain.size();
            }
            i = m - l - 1;
            for (j = n - l - 1; j > l; j--) {
                grid[i][j] = chain[index];
                index = (index + 1) % chain.size();
            }
            j = l;
            for (i = m - l - 1; i > l; i--) {
                grid[i][j] = chain[index];
                index = (index + 1) % chain.size();
            }
        }
        return grid;
    }
};