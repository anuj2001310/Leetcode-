class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> rowSum(n, 0), colSum(m, 0);
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                tot += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
        if (tot & 1)
            return false;

        long long pref = 0LL;
        for (int i = 0; i < n - 1; ++i) {
            pref += rowSum[i];
            if ((pref << 1) == tot)
                return true;
        }

        pref = 0LL;
        for (int i = 0; i < m - 1; ++i) {
            pref += colSum[i];
            if ((pref << 1) == tot)
                return true;
        }
        
        return false;
    }
};